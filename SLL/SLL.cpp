// added comments to explain steps
// and for debugging, you may better know then me

#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* next;

		Node(int d) {
			data = d;
			next = NULL;
		}
};

class SLL {
		Node* head;
	public:
		SLL() {
			head = NULL;
		}

		void add_at_start(int d) {
			cout << "adding at start: " << d << endl; // *
			// step 1. make a newnode and add data
			// step 2. always make newnode->next = head,
			// { if head is NULL, so newnode->next = NULL otherwise newnode->next will be head }
			// finally make the newnode the head of s-linked list

			Node* newnode = new Node(d);
			newnode->next = head;
			head = newnode;
		}

		void add_at_end (int d) {
			cout << "adding at end: " << d << endl; // *
			// step 1. create a newnode and add data
			// step 2. always make next ptr = NULL
			// step 3. if list is empty, make newnode head of list
			//		   else find last node and make its next = newnode

			Node* newnode = new Node(d);
			newnode->next = NULL;

			if(!head) {
				head = newnode;
			} else {
				Node* temp = head;
				while (temp->next) {
					temp = temp->next;
				}
				temp->next = newnode;
			}
		}

		void add_after (int p, int d) {
			cout << "adding {" << d << "} after position " << p << endl; // *
			// step 1. create a newnode and add data
			// step 2. find node after given position p
			// step 3. if position is greater then no. of nodes present
			//		- return or show error
			// step 4. set newNode->next = temp->next
			// step 5. if the position is valid, insert the new node
			// step 6. set temp's next to newNode

			Node* newnode = new Node(d);

			int c = 1; // shows current position
			Node* temp = head;
			while (temp && c < p) {
				temp = temp->next;
				c++;
			}
			if (p > c) {
				// add_at_end(d);
				cout << "cant find position " << p << endl;
				cout << "---" << endl;
				return;
			}
			newnode->next = temp->next;
			temp->next = newnode;
		}

		void sort () {
			cout << "sorting SLL" << endl; // *
			// I used Bubble sort algorithm, you choose your favr

			// step 1. Check if the SLL is empty or has only one node
			// step 2. Use a do-while loop for sort
			// step 3. compare adjacent nodes and swap data if needed
			// stpe 4. continue the loop until the entire SLL is sorted

			if (!head || head->next == NULL) {
				cout << "empty or only one node" << endl;
			} else {
				bool swaped;
				Node* curr;
				Node* temp = NULL;
				do {
					swaped = false;
					curr = head;

					while (curr->next != temp) {
						if (curr->data > curr->next->data) {
							int t = curr->data;
							curr->data = curr->next->data;
							curr->next->data = t;
							swaped = true;
						}
						curr = curr->next;
					}
					temp = curr;
				} while (swaped);
			}
			cout << "sorted" << endl; // *
		}

		void print() {
			cout << "Printing SLL" << endl; // *
			// step 1. Check if SLL is empty { return if it is }
			// step 2. initialize a pointer to traverse the list
			// step 3. traverse the list and print each node's data

			if (!head) {
				cout << "empty SLL" << endl;
			} else {
				Node* temp = head;
				while (temp) {
					cout << temp->data << "\t";
					temp = temp->next;
				}
				cout << endl;
			}
			cout << "---" << endl; // *
		}

		// ----		delete functions

		void del_from_start () {
			cout << "deleting from start: "; // *
			// 1. Check if the SLL is empty
			// 2. Store the node to be deleted in a temporary pointer (temp = head)
			// 3. Update the head (head = head->next)
			// 4. Deallocate the memory (delete temp)
			// 5. Return the data of the deleted node (optional)

			if(!head) {
				cout << "empty already" << endl;
			} else {
				Node* temp = head;
				head = head->next;
				cout << temp->data << endl; // *
				cout << "deleted " << temp->data << endl;
				delete temp;
			}
		}

		void del_from_end () {
			cout << "deleting from end: "; // *
			// 1. Check if SLL is empty
			// 2. Find the second last node
			// 3. Store the last node
			// 4. Remove the last node from SLL
			// 5. Free the memory of the last node

			if (!head) {
				cout << "empty already" << endl;
			} else {
				if(!head->next) {
					cout << head->data << endl; // *
					cout << "deleted " << head->data << endl;
					delete head;
					head = NULL;
				} else {
					Node* temp = head;
					Node* prev = NULL;
					while (temp->next) {
						prev = temp;
						temp = temp->next;
					}
					cout << temp->data << endl; // *
					cout << "deleted " << temp->data << endl;
					delete temp;
					prev->next = NULL;
				}
			}
		}

		void del_after (int p) {
			// 1. Check if SLL is empty
			// 2. Go to the node at the given position
			// 3. Store the next node (to be deleted)
			// 4. Connect the node at the given position to the node after the next node
			// 5. DEL the next node
			// 6. Free the memory of removed node

			if (!head) {
				cout << "empty already " << endl;
			} else {
				Node* temp = head;
				int c = 1;
				while (temp && c<p) {
					temp = temp->next;
					c++;
				}
				if (!temp || !temp->next) {
					cout << "invlid position " << p << endl;
					return;
				}
				Node* temp2 = temp->next;
				temp->next = temp2->next;
				cout << "deleted after " << p << ":::" << temp->data << endl;
				delete temp2;
			}
		}

		void reverse () {
			cout << "reversing SLL" << endl; // *
			// 1. Check if the list is empty
			// 2. Start at the beginning of the SLL
			// 3. Move through the SLL, reversing the direction of each node's pointer
			// 4. Keep going until you reach the end of the SLL
			// 5. Update the head of SLL

			if (!head) {
				cout << "empty" << endl;
			} else {

				Node* current = head;
				Node* next = NULL;
				Node* prev = NULL;

				while (current) {
					next = current->next;
					current->next = prev;
					prev = current;
					current = next;
				}
				head = prev;
			}
			cout << "reversed\n---" << endl;
		}

};

int main() {
	SLL s;
	s.print();
	s.add_after(2, 34); // cant find position
	s.print();

	s.add_at_start(2);
	s.add_at_start(4);
	s.add_at_start(5);
	s.print();

	s.add_at_end(45);
	s.add_at_end(46);
	s.print();

	s.add_at_start(10);
	s.add_at_end(20);

	s.add_after(2, 34);
	s.add_after(6, 64);
	s.add_after(5, 74);
	s.print();

	cout << "\noriginal SLL" << endl;
	s.print();
	s.sort();
	s.print();

	cout << "\n---deleting functions---\n" << endl; // *
	s.del_from_start();
	s.print();

	s.del_from_end();
	s.print();

	s.del_after(2);
	s.del_after(99); // invalid postion
	s.print();
	
	cout << "\noriginal SLL" << endl;
	s.print();
	s.reverse();
//	s.add_at_start(23);
	s.print();

	// QUIZ:
	// Without running what should be the SLL at the end

	system("pause");
	return 0;
}
