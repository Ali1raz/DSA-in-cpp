/* Scenario:
	Design a queue data structure to simulate a supermarket checkout system. Each customer enters
the queue with a unique customer ID and the number of items they want to purchase. Implement
operations to add customers to the queue, remove customers when they are served, and display the
current customer being served along with their details. */

#include <iostream>
using namespace std;

// Queue using SLL

class Node {
	public:
		int id;
		int qnt;
		Node* next;

		Node (int i, int q) {
			id = i;
			qnt = q;
			next = NULL;
		}
};

class QLL {
		Node* front;
		Node* rear;
	public:
		QLL () {
			front = rear = NULL;
		}

		void add (int i, int q) {
			cout << "adding {" << i << "} to Queue" << endl; // **
			// new nodes will be added at end in Queue

			Node* newnode = new Node(i, q);
			if (rear == NULL) {
				front = newnode;
			} else {
				rear->next = newnode;
			}
			rear = newnode;
		}

		void serve () {
			if (!front) {
				cout << "Queue is empty" << endl;
			} else {
				// when served, nodes added first will be removed first
				// { First Come First Serve }

				if (front) {
					Node* temp = front;
					front = front->next;
					if (front == NULL) {
						rear = NULL;
					}
					cout << "\nserving: " << temp->id << endl;
					delete temp;
					cout << "served" << endl;
				}
			}
			cout << "---" << endl;
		}

		void current () {
			if (front == NULL) {
				cout <<"empty Queue" << endl;
			} else {
				cout << "current to serve:\nid:" << front->id << " with Qnt: " << front->qnt << endl;
			}
			cout << "---" << endl;
		}

		void print () {
			if (front == NULL) {
				cout << "Empty Queue" << endl;
			} else {
				cout << "\nprinting Queue:" << endl;
				Node* temp = front;
				while (temp != NULL) {
					cout << "Customer id: " << temp->id << " with Qnt: " << temp->qnt << endl;
					temp = temp->next;
				}
			}
			cout << "---" << endl;
		}
};

int main () {
	QLL q;
	// use a while to loop to input customers Qnt and static int::id in Node class to generate unique id's each time
	q.add(201, 23);
	q.add(232, 24);
	q.add(243, 27);
	q.add(265, 26);
	q.add(224, 27);
	q.print();

	q.current();
	q.serve();
	q.serve();
	q.print();

	system("pause");
	return 0;
}
