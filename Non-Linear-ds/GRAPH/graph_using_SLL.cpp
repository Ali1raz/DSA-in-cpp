#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* link;
};

class Linklist {
	Node* head;
	Node* tail;
	public:
		Liklist () {
			head = NULL;
			tail = NULL;
		}
		
		void append(int d) {
			Node* n1 = new Node;
			n1->data = d;
			n1->link= NULL;
			if (head == NULL) {
				head = n1;
				tail = n1;
			} else {
				tail->link = n1;
				tail = tail->link;
			}
		}
		
		void display () {
			Node* temp = head->link;
			while (temp!= NULL) {
				cout << temp->data <<" ";
				temp = temp->link;
			}
			cout << endl;
		}
		
		int get_header () {
			return head->data;
		}
};

const int max_ver = 10;
Linklist vertices[max_ver];
int vCount = 0;
int adjMatrix[max_ver][max_ver] = {0};

void add_vertex (int v) {
	vertices[vCount].append(v);
	vCount++;
} 

void addEdge (int v1, int v2) {
	for (int i=0;i<vCount;i++) {
		if (vertices[i].get_header() == v1) {
			vertices[i].append(v2);
			adjMatrix [i][v2] = 1;
			break;
		}
	}
}

void dispay_graph () {
	cout << "printing graph:" << endl;
	for (int i=0;i<vCount;i++) {
		cout << "vertex is " << vertices[i].get_header() << "\t";
		vertices[i].display();
	}
	cout << "---" << endl;
	
	cout << "Adjacency Matrix: " << endl;
	for (int i=0;i<vCount;i++) {
		for (int j=0;j<vCount;j++) {
			cout << adjMatrix[i][j] << "\t";
		}
		cout << endl;
	}
}

int main () {
	add_vertex(5);
	add_vertex(10);
	add_vertex(20);
	add_vertex(40);
	add_vertex(9);
	
	addEdge(5, 10);
	addEdge(5, 20);
	addEdge(5, 40);
	addEdge(10, 40);
	addEdge(40, 20);
	addEdge(9, 20);
	
	dispay_graph();
	
	system("pause");
	return 0;
}
