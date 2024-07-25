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

class CDLL {
		Node* head;
		Node* tail;
	public:
		CDLL () {
			head = tail = NULL;
		}

		void add_start(int d) {
			cout <<"adding at start: " << d << endl; // **
			/*  1. Create New Node and set data.
				2. Check Empty List:
					- If empty, set head and tail = newnode.
					- Point newnode-> next and newnode->prev to itself.
				3. List Not Empty:
					- Point newnode->next = head.
					- Point new node->prev = tail.
					- Update head->prev = newnode.
					- Update tail->next = newnode.
				4. Update Head: Set head = newnode. */

			Node* newnode = new Node(d);
			if (head) {
				newnode->next = head;
				newnode->prev = tail;
				head->prev = newnode;
				tail->next = newnode;
				head = newnode;
			} else {
				head = tail = newnode;
				newnode->next = head;
				newnode->prev = head;
			}
		}

		void add_end (int d) {
			cout << "Adding at end " << d << endl; // **
			/*  1. Create newnode and set data.
				2. Check Empty List:
					- If empty, set head and tail to new node.
					- point newnode->next and newnode->prev to itself
				3. List Not Empty:
					- Point newnode->prev = tail.
					- Point newnode->next = head.
					- Update tail->next = newnode.
					- Update head->prev = newnode.
					- Update tail: Set tail = newnode. */

			Node* newnode = new Node(d);
			if (head) {
				newnode->prev = tail;
				tail->next = newnode;
				head->prev = newnode;
			} else {
				head = newnode;
				newnode->prev = head;
			}
			newnode->next = head;
			tail = newnode;
		}

		void add_at (int pos, int d) {
			cout << "adding {" << d << "} after " << pos << endl; // **
			/*  1. Create New Node and set data.
				2. If cdll is empty, return.
				3. Traverse to Position:
					- Start from head and move to the desired position.
					- save current position
				4. Insert Node:
					- Set newnode->next = current node->next.
					- Set newnode's prev = current node.
					- Update current node's next's prev = newnode.
					- Update current node's next = newnode */

			if (!head) {
				cout << "List is empty." << endl;
				return;
			}
			Node* newnode = new Node(d);
			Node* temp = head;
			int currentPos = 1;
			if (pos == currentPos) {
				add_start(d);
				return;
			}
			while (currentPos < pos) {
				temp = temp->next;
				if (temp == head) {
					cout << "Position out of bounds." << endl;
					delete newnode; // Free allocated memory
					return;
				}
				currentPos++;
			}
			newnode->next = temp->next;
			newnode->prev = temp;
			temp->next->prev = newnode;
			temp->next = newnode;
			if (temp == tail) {
				tail = newnode;
			}
		}

		void print_forward () {
			cout << "printing CDLL" << endl;
			/*  1. If CDLL is empty, return.
				2. Start from Head: Initialize a pointer to head.
				3. Traverse cdll:
					- Print the data of the current node.
					- Move to the next node.
					- Repeat until you reach back to head.*/

			if (!head) {
				cout << "empty CDLL" << endl;
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

		void print_reverse() {
			cout << "printing in reverse" << endl; // **
			/*  1. Start from tail and traverse backward using the prev
				2. Print each node's data until back to tail */

			if (!head) {
				cout << "List is empty." << endl;
			} else {
				Node* temp = tail;
				do {
					cout << temp->data << "\t";
					temp = temp->prev;
				} while (temp != tail);
				cout << endl;
			}
		}

		void sort () {
			cout << "sorting CDLL" << endl; // **
			/*  1. Check Empty List: If the list is empty, return.
				2. Outer Loop: Traverse from head to tail repeatedly.
				3. Inner Loop: For each node, compare its data with the next node's data.
					- If the current node's data is greater, swap the data.
				4. Repeat until no more swaps are needed */

			if (!head) {
				cout << "List is empty." << endl;
			} else {
				bool swapped;
				Node* current;
				Node* last = NULL;
				do {
					swapped = false;
					current = head;
					while (current->next != head) {
						if (current->data > current->next->data) {
							int temp = current->data;
							current->data = current->next->data;
							current->next->data = temp;
							swapped = true;
						}
						current = current->next;
						if (current == last) break;
					}
					last = current;
				} while (swapped);
			}
		}

		void delete_start() {
			if (!head) {
				cout << "CDLL is empty" << endl;
			} else {
				cout << "deleting from start: "; // **
				Node* temp = head;
				if (head == tail) { // Only one node in the list
					cout << temp->data << endl; // **
					delete temp;
					head = tail = NULL;
				} else {
					head = head->next;
					head->prev = tail;
					tail->next = head;
					cout << temp->data << endl; // **
					delete temp;
				}
			}
		}
		void delete_end() {
			if (!head) {
				cout << "CDLL is empty" << endl;
				return;
			}

			if (head == tail) {
				delete head;
				head = tail = NULL;
			} else {
				Node* temp = tail;
				tail = tail->prev;
				tail->next = head;
				head->prev = tail;
				delete temp;
			}
		}

		void delete_after(int pos) {
			if (!head || pos < 0) {
				cout << "List is empty or position is invalid." << endl;
				return;
			}
			Node* temp = head;
			for (int i = 0; i < pos; i++) {
				if (!temp->next) {
					cout << "Position out of bounds." << endl;
					return;
				}
				temp = temp->next;
			}
			Node* to_delete = temp->next;
			if (!to_delete) {
				cout << "No node to delete after the given position." << endl;
				return;
			}
			temp->next = to_delete->next;
			if (to_delete->next) {
				to_delete->next->prev = temp;
			}
			delete to_delete;
		}




};

int main () {
	CDLL c;
	c.add_start(23);
	c.add_start(25);
	c.add_at(2, 76);
	c.add_at(4, 76);
	c.add_end(34);
	c.print_forward();

	cout << "original CDLL" << endl;
	c.print_forward();
	c.sort();
	c.print_forward();

	c.print_reverse();
	c.print_forward();

	/*	--- deleting scenarios ---	*/
	c.delete_start();
//	c.delete_start();
//	c.add_start(29);
//	c.add_end(21);
//	c.add_start(28);
	c.delete_end();
	c.delete_after(2);
	c.print_forward();

	system("pause");
	return 0;
}
