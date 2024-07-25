#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int stack[MAX_SIZE];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX_SIZE - 1;
}

void push(int value) {
    if (top == MAX_SIZE - 1) {
        cout << "Stack is full, can't push another value" << endl;
        return;
    }

    top++;
    stack[top] = value;
    cout << "Pushed element: " << value << endl;
}

int pop() {
    if (top == -1) {
        cout << "Stack is empty" << endl;
        return -1;
    }

    int poppedValue = stack[top];
    top--;
    return poppedValue;
}

int peek() {
    if (top == -1) {
        cout << "Stack is empty" << endl;
        return -1;
    }

    return stack[top];
}

void print() {
    if (top == -1) {
        cout << "stack is empty" << endl;
    } else {
	    cout << "printing stack:" << endl;
	    for (int i = top; i >= 0; i--) {
	        cout << stack[i] << "\t";
	    }
	    cout << endl;
	}
	cout << "---" << endl;
}

// there are more methods available
// add by yourself, you learned a lot till now

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    print();

    cout << "Top element: " << peek() << endl;

    cout << "Popped element: " << pop() << endl;
    cout << "Popped element: " << pop() << endl;

    cout << "Top element: " << peek() << endl;

    print();

    return 0;
}

