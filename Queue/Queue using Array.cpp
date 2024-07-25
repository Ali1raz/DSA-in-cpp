#include <iostream>
using namespace std;

class Queue {
	int* arr;
	int capacity;
	int front;
	int rear;
	int count;
	
	public:
		Queue (int s) {
			arr = new int[s];
			capacity = s;
			front = 0;
			rear = -1;
			count = 0;
		}
		
		void enqueue (int d) {
			if (count == capacity) {
				cout << "queue full " << endl;
			} else {
				rear = (rear+1) % capacity;
				arr[rear] = d;
				count++;
			}
		}
		
		void dequeue () {
			if (count == 0) {
				cout << "already empty" << endl;
			} else {
				front = (front+1) % capacity;
				count--;
			}
		}
};

int main() {
	cout << "ali" << endl;

	system("pause");
	return 0;
}

