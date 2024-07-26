#include <iostream>
using namespace std;

const int maxVrtices = 100;
int vertices[maxVrtices];
int graph[maxVrtices][maxVrtices];
int vCount = 0;

void addVertex(int v) {
	vertices[vCount] = v;
	vCount++;
}

void addEdge (int u, int v) {
	graph[u][v] = 1; 
	graph[v][u] = 1; // undirected graph
}

int getIndex (int v) {
	for (int i=0;i<maxVrtices; i++) {
		if (vertices[i] == v) {
			return i;
		}
	}
}

void printGraph () {
	cout << "printing Graph:" << endl;
	for (int i=0;i<vCount; i++) {
		cout << vertices[i] << " ";
	}
	cout << endl;
	
	cout << "Adjacency matrix:" << endl;
	for (int i=0;i<vCount; i++) {
		for (int j=0;j<vCount; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	addVertex(30);
	addVertex(20);
	addVertex(1);
	addVertex(16);
	addVertex(4);
	
	addEdge(getIndex(30), getIndex(20));
	addEdge(getIndex(4), getIndex(16));
	addEdge(getIndex(1), getIndex(20));
	
	printGraph();
	return 0;
}
