#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Edge{
public:
	int from;
	int to;
	int weight;
	bool visited;
	Edge(){
		from = to = weight = 0;
		visited = false;
	}
	Edge(int f, int t, int w){
		from = f;
		to = t;
		weight = w;
		visited = false;
	}
};
void get_min_tree(vector<Edge> &e, vector<int> &vex, int &p){
	int i = 0;
	for (;i < e.size();i++){
		if (vex[e[i].from]^vex[e[i].to] && !e[i].visited){
			vex[e[i].from] = vex[e[i].to] = 1;
			p += e[i].weight;
			e[i].visited = true;
			cout << e[i].from << " " << e[i].to << endl;
			break;
		}
	}
}

bool cmp(Edge e1,Edge e2){
	return e1.weight < e2.weight;
}
int main(){
	int N = 0, M = 0;
	while (cin >> N >> M){
		if (N == 0) return 0;
		if (N<M - 1)
		{
			cout << "?" << endl;
			continue;
		}
		vector<Edge> edges(N);
		for (int i = 0; i<N; i++){
			cin >> edges[i].from >> edges[i].to >> edges[i].weight;
		}
		sort(edges.begin(),edges.end(),cmp);
		vector<int> vex(M + 1, 0);
		vex[edges[0].from] = vex[edges[0].to] = 1;
		edges[0].visited = true;
		int price = edges[0].weight;
		cout << edges[0].from << " " << edges[0].to << endl;
		for (int i = 1; i<M-1; i++){
			get_min_tree(edges, vex, price);
		}
		cout << price << endl;
	}

}