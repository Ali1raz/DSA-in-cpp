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

class CSLL {
		Node* head;
		Node* tail;

	public:
		CSLL () {
			head = tail = NULL;
		}

		void add_start (int d) {
			cout << "adding at start: " << d << endl;
			// 1. Create a new node, and add data.
			// 2. If the CSLL is empty, makes the new node point to itself (like a circle).
			// 3. If the CSLL is not empty, add newnode to beginning of CSLL
			// 4. Update the head = newnode.
			// 5. Makes sure yhe last node in the list points to the new node (to keep the circle).


			Node* newnode = new Node(d);
			if (!head) {
				tail = newnode;
				newnode->next = newnode;
			} else {
				newnode->next = head;
				tail->next = newnode;
			}
			head = newnode;
		}

		void add_end (int d) {
			cout << "addin at end: " << d << endl;
			// 1. Create a new node with data.
			// 2. If the CSLL is empty:
			//		- Set head and tail to the newnode.
			//		- Make the newnode point to itself (circle)
			// 3. If the CSLL is not empty:
			//		- Add the newnode to the end
			//		- Update tail = newnode
			//		- Make the last node point to the newnode (keep circle)

			Node* newnode = new Node(d);
			if (!head) {
				head = newnode;
				newnode->next = newnode;
			} else {
				newnode->next = head;
				tail->next = newnode;
			}
			tail = newnode;
		}

		void add_after (int p, int d) {
			cout << "adding {" << d << "} after: " << p << endl; // **
			// 1. Create a new node
			// 2. If you want to add at the start, just add it to the start
			// 3. If you want to add somewhere else, find the node right before the position
			// 4. Connect the new node to the next node of the node you found
			// 5. Connect the node you found to the new node

			Node* newnode = new Node(d);
			if (!head || p == 0) {
				// add_start(d);
				cout << "Invalid postion: " << p << endl;
			} else {
				int c = 1;
				Node* temp = head;
				while (c < p) {
					c++;
					temp = temp->next;
					if (temp == head) {
						cout << "invalid position: " << p << endl;
						return;
					}
				}
				newnode->next = temp->next;
				temp->next = newnode;
				cout << newnode->data << " ";
			}
		}

		void reverse () {
			cout << "reversing CSLL" << endl; // **
			// 1. Find the last node (the one that points to the head).
			// 2. Break the circle by making the last node point to nothing (NULL).
			// 3. Reverse the list by swapping the next pointers of each node.
			// 4. Find the new last node (the original head).
			// 5. Make the new last node point to the new head to re-form the circle.

			if (!head || head->next == head) {
				cout << "emoty or single" << endl;
			} else {
				Node* curr = head;
				Node* next;
				Node* prev;
				do {
					next = curr->next;
					curr->next = prev;
					prev = curr;
					curr = next;
				} while (curr != head);
				head->next = prev;
				head = prev;
				cout << "reversed " << endl;
			}
			cout << "---" << endl; // **
		}

		void sort () {
			cout << "sorting csll" << endl; // **

			// 1. Start at the head of the list.
			// 2. Compare the current node's value with the next node's value.
			// 3. If they're in the wrong order, swap them.
			// 4. Move to the next node and repeat steps 2-3 until you reach the head again.
			// 5. Repeat steps 1-4 until no more swaps are needed.

			if (!head || head->next == head) {
				cout << "empty or singel" << endl;
			} else {
				bool swaped;
				Node* curr;
				do {
					curr = head;
					swaped = false;
					do {
						if (curr->data > curr->next->data) {
							int t = curr->data;
							curr->data = curr->next->data;
							curr->next->data = t;
							swaped = true;
						}
						curr = curr->next;
					} while (curr->next != head);
				} while (swaped);
				cout << "sorted" <<endl; // **
			}
			cout << "----" << endl;
		}

		void print() {
			// 1. Start at the head of the list.
			// 2. Print the current node's value.
			// 3. Move to the next node.
			/// 4. Repeat steps 2-3 until you reach the head again.

			if (!head) {
				cout << "empty CSLL" << endl;
			} else {
				Node* temp = head;
				do {
					cout << temp->data << "\t";
					temp = temp->next;
				} while (temp != head);
				cout << endl;
			}
			cout << "---" << endl;
		}

		void del_start () {
			cout << "deleting from start: "; // **
			if (!head) {
				cout << "already empty CSLL" << endl;
			} else {
				Node* temp = head;
				if (head == tail) {
					head = tail = NULL;
				} else {
					head = head->next;
					tail->next = head;
				}
				cout << temp->data << endl; // **
				delete temp;
			}
		}

		void del_end () {
			cout << "deleting from end: "; // **
			// 1. Check if list is empty. If so, return
			// 2. Find last-second node
			// 3. Remove last node and connect last-second node to head
			// 4. Print and free deleted node

			if (!head) {
				cout << "empty already CSLL" << endl;
			} else {
				Node* temp = head;
				if (head== tail) {
					cout << head->data << endl;
					delete head;
					head= tail = NULL;
				} else {
					while (temp->next != tail) {
						temp = temp->next;
					}
					Node* t = tail;
					tail = temp;
					tail->next = head;
					cout << t->data << endl;
					delete t;
				}
			}
		}

		void del_after (int p) {
			cout <<"deleting after: " << p << ": "; // **
			// 1. Check if list is empty, if so, return
			// 2. Find node at position p-1
			// 3. Remove next node and connect others
			// 4. free deleted node.

			if (!head) {
				cout << "empty already CSLL" << endl;
			} else {
				if (p == 0) {
					Node* temp = head;
					head = head->next;
					tail->next = head;
					cout << temp->data << endl; // **
					delete temp;
				} else {
					Node* temp = head;
					int c= 1;
					while (c < p) {
						temp = temp->next;
						c++;
						if (temp == head) {
							cout <<"invalid position: " << p << endl;
							return;
						}
					}
					if (temp->next == head) {
						cout << "no node to delete after " << p << endl;
						return;
					}
					Node* t = temp->next;
					temp->next = t->next;
					if (t == tail) {
						tail = temp;
					}
					cout << t->data << " "; // **
					delete t;
				}
			}
		}
};

int main () {
	CSLL c;
//	c.del_start();
	c.add_start(20);
//	c.del_start();
	c.del_end();
	c.add_start(21);
	c.add_start(24);
	c.print();

	c.add_end(34);
	c.add_end(35);
	c.add_end(37);
	c.print();

	cout << "original CSLL" << endl;
	c.print();
	c.reverse();
	c.print();

	c.sort();
	c.print();
	c.reverse();

	/*	deleting senarios	*/

	c.del_start();
//	c.del_end();
	c.add_start(22);
	c.add_end(12);
	c.print();

	system("pause");
	return 0;
}
