#include"graph.h"
using namespace std;

int main() {
	Graph graph = Graph();
	string fn = "pmed0.txt";
	graph.init_graph(fn);
	graph.BFS();
	cout << endl;
	graph.DFS();

}

