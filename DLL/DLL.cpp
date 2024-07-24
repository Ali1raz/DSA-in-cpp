#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* next;
		Node* prev;

		Node(int d) {
			data = d;
			next = NULL;
			prev = NULL;
		}

};

class DLL {
		Node* head;
		Node* tail;
	public:
		DLL () {
			head = NULL;
			tail = NULL;
		}

		void add_at_start (int d) {
			cout << "adding at start: " << d << endl; // **
			// 1. Create a new node
			// 2. If the DLL is empty, make it the head and tail
			// 3. If the DLL is not empty:
			//	 - Connect the new node to the current head
			//	 - Update the current head to point to the new node
			//	 - Make the new node the new head

			Node* newnode = new Node(d);
			newnode->prev = NULL;
			newnode->next = head;
			if (!head) {
				tail = newnode;
			} else {
				head->prev = newnode;
			}
			head = newnode;
		}

		void add_at_end (int d) {
			cout << "adding at end: " << d << endl; // **
			// 1. Create a new node
			// 2. If the list is empty, make it the head and tail
			// 3. If the list is not empty:
			//	- Go to the last node
			//	- Connect the new node to the last node
			//	- Update the last node to point to the new node
			//	- Make the new node the new last node

			Node* newnode = new Node(d);
			newnode->prev = tail;
			newnode->next = NULL;
			if (!head) {
				head = newnode;
			} else {
				tail->next = newnode;
			}
			tail = newnode;
		}

		void add_after_postition (int p, int d) {
			cout << "adding {" << d << "} after " << p << endl; // **
			// 1. Create a new node and add data
			// 2. If the position is 0 or the list is empty, add at start.
			// 3. If the position is beyond the list length, add at end.
			// 4. Otherwise:
			//	- Go to the node at the given position.
			//	- Connect the new node to the node and its next node.
			//	- Update the pointers to include the new node.

			Node* newnode = new Node(d);
			Node* temp = head;
			int c = 1;
			while (temp && c<p) {
				temp = temp->next;
				c++;
			}
			if (!temp || p <= 0) {
				cout << "invlaid position " << p << endl;
			} else {
				if (temp->next) {
					temp->next->prev = newnode;
				} else {
					tail = newnode;
				}
				newnode->next= temp->next;
				newnode->prev = temp;
				temp->next = newnode;
			}
		}

		void reverse () {
			cout << "reversing DLL " <<endl; // **
			// 1. Start at the beginning of the DLL
			// 2. Move through the DLL, swapping the next and prev pointers of each node
			// 3. Keep going until you reach the end of DLL
			// 4. The last node you visited is now the new head of the DLL

			if (!head || !head->next) {
				cout<< "empty or singel node" << endl;
			} else {
				Node* temp = head;
				head = tail;
				tail = temp;

				Node* curr = head;
				while (curr) {
					Node* prev = curr->prev;
					curr->prev = curr->next;
					curr->next = prev;
					curr = curr->next;
				}
				cout << "reversed DLL" << endl; // **
			}
			cout << "---" << endl;
		}

		void sort () {
			cout << "sorting DLL" << endl; // **
			// -: BUBBLE SORT :-
			// 1. Start at the beginning of the DLL
			// 2. Compare the current node's data with the next node's data.
			// 3. If they're in the wrong order, swap them.
			// 4. Move to the next node and repeat steps 2-3.
			// 5. Keep going until you reach the end of DLL
			// 6. Repeat the whole process until no more swaps are needed

			if (!head || !head->next) {
				cout << "empty or single node" << endl;
			} else {
				Node* curr;
				Node* temp = NULL;
				bool swaped;
				do {
					curr = head;
					swaped = false;
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
				cout << "sorted" << endl; // **
			}
			cout << "---" << endl;
		}

		void print_f () {
			cout << "\nprinting forward" << endl; // **
			// 1. Start at the head of the list
			// 2. Print the data of the current node
			// 3. Move to the next node
			// 4. loop 2-3 until you reach the end of DLL

			if (!head) {
				cout << "empty DLL" << endl;
			} else {
				Node* temp = head;
				while (temp) {
					cout << temp->data << "\t";
					temp = temp->next;
				}
				cout << endl;
			}
			cout << "---" << endl;
		}
		void print_r () {
			cout << "\nprintin in reverse:" << endl; // **

			if (!head) {
				cout << "empty DLL" << endl;
			} else {
				Node* temp = tail;
				while (temp) {
					cout << temp->data << "\t";
					temp = temp->prev;
				}
				cout << endl;
			}
			cout << "---" << endl;
		}
		
		/*	deletion scenarios	*/

		void del_from_start () {
			cout << "deleting from start "; // **
			if (!head) {
				cout << "empty DLL" << endl;
			} else {
				if (!head->next) {
					cout << head->data << endl; // **
					cout << "deleted head" <<endl;
					delete head;
					head = NULL;
					tail = NULL;
				} else {
					Node* temp = head;
					cout << head->data << endl; // **
					head = head->next;
					cout << "deleted " << temp->data << endl;
					delete temp;
					head->prev = NULL;
				}
			}
		}

		void del_from_end () {
			cout << "deleting from end"; // **
			if (!head) {
				cout << "empty DLL" << endl;
			} else {
				if (!head->next) {
					cout << tail->data << endl; // **
					cout << "deleted tail " << tail->data << endl;
					delete tail;
					tail = NULL;
					head = NULL;
				} else {
					Node* temp = tail;
					tail = tail->prev;
					cout << temp->data << endl; // **
					cout << "deleted tail " << temp->data << endl;
					delete temp;
					tail->next = NULL;
				}
			}
			cout << "---" << endl;
		}

		void del_at (int p) {
			if (!head) {
				cout << "empty DLL" << endl;
			} else {
				int c = 1;
				Node* temp = head;
				while (temp && c <p) {
					c++;
					temp = temp->next;
				}

				if (!temp) {
					cout << "invalid pos::" << p << endl;
					return;
				}

				if (temp->next) {
					temp->next->prev = temp->prev;
				} else {
					temp->prev->next = NULL;
					tail = temp->prev;
				}

				if (temp->prev) {
					temp->prev->next = temp->next;
				} else {
					temp->next->prev = NULL;
					head = temp->next;
				}
				cout << "deleted at post: " << p << "::" << temp->data << endl;
				delete temp;
			}
		}

};


int main() {
	DLL d;
	d.add_at_start(23);
	d.add_at_start(24);
	d.add_at_start(21);
	d.print_f();

	d.add_at_end(49);
	d.add_after_postition(-1, 65);
	d.add_after_postition(3, 53);
	d.add_at_end(47);
	d.print_f();
	d.print_r();

	d.sort();
	d.print_f();

	/* delting functoins */
	
	d.del_from_start();
	// d.add_at_start(27);
	d.print_f();
	d.del_at(3);
	d.print_f();
	
	d.del_from_end();
	d.print_f();
	
	d.add_at_start(36); // **
	d.add_at_start(38); // **
	d.print_f(); // **
	
	d.print_r(); // **
	
	
	// QUIZ:
	// Without running the program, what is value of DLL at the line 297

	system("pause");
	return 0;
}
