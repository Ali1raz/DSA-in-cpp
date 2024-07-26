#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int queue[MAX_SIZE];
int front = -1; 
// because there is no element in Queue
// this shows Queue is empty
int rear = -1;

bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return (rear + 1) % MAX_SIZE == front;
}

void enqueue(int data) {
    if (isFull()) {
        cout << "Queue is full" << endl;
        return;
    }

    if (isEmpty()) {
        front = 0;
    }

    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = data;
}

int dequeue() { // ti remove element from start
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;
    }

    int data = queue[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }

    return data;
}

int getFront() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;
    }

    return queue[front];
}

void print() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    }else {
	    cout << "Printing Queue:" << endl;
	    int i = front;
	    while (i != rear+1) {
	        cout << queue[i] << "\t";
	        i = (i + 1) % MAX_SIZE;
	    }
	    cout << endl;
//	    cout << queue[i] << endl;
	}
	cout << "---" << endl;
}

void getSize() {
	cout << "Size of Queue: ";
    if (isEmpty()) {
        cout << 0;
    } else {
	    if (front <= rear) {
	        cout << rear - front + 1;
	    } else {
	        cout << MAX_SIZE - front + rear + 1;
	    }
	}
	cout << endl;
}

void clear() {
    front = rear = -1;
    cout << "Queue cleared" << endl;
}

void peek() {
	cout << "Peek o Queue: ";
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
    	cout << queue[front];
	}
	cout << endl;
}


int main() {
    enqueue(1);
    enqueue(10);
    enqueue(12);
    enqueue(13);
    enqueue(25);
    enqueue(35);
    enqueue(47);
    enqueue(23);
    enqueue(98);
    
    print();

    cout << "Front element: " << getFront() << endl;

    cout << "Dequeued element: " << dequeue() << endl;
    cout << "Dequeued element: " << dequeue() << endl;

    cout << "Front element: " << getFront() << endl;
    getSize();
    
    peek();
	
	system("pause");
    return 0;
}

