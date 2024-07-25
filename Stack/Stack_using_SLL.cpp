#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// stack operates on the principle of LIFO, 
// meaning that the most recently added element is 
// always the first one to be removed.

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << "Pushed element: " << value << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
        	cout << "removing top: " << top->data << endl;
	        Node* temp = top;
	        top = top->next;
	        delete temp;
		}
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return top->data;
    }

    void print() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
	        cout << "Printing Stack:" << endl;
	        Node* current = top;
	        while (current != NULL) {
	            cout << current->data << "\t";
	            current = current->next;
	        }
	        cout << endl;
		}
		cout << "---" << endl;
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.print();

    cout << "Top element: " << stack.peek() << endl;

    stack.pop();
    stack.pop();

    cout << "Top element: " << stack.peek() << endl;

    stack.print();

    return 0;
}

