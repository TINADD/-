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
bool cmp(Edge e1,Edge e2){
	return e1.weight < e2.weight;
}

int find(int in,vector<int> &p){
	int s = in;
	while(p[s]>=0){
		s = p[s];
	}
	while(in != s){
		int tmp = p[in];
		p[in] = s;
		in = tmp;
	}
	return s;
}

int Union(int from,int to,vector<int> &p){
	int f = p[from];
	int t = p[to];
	int sum = f+t;
	if(f > t)
	{
		p[from] = to;
		p[to] = sum;
	}else{
		p[to] = from;
		p[from] = sum;
	}
	return 0;
}
int main(){
	int n=0,m=0;
	while(cin>>n>>m){
		vector<Edge> edges(n);
		vector<int> parent(m+1,-1);
        for(int i=0;i<n;i++){
            cin >> edges[i].from >> edges[i].to >> edges[i].weight;
        }
		sort(edges.begin(),edges.end(),cmp);
		int edge_num = 0;
		int price = 0;
		for(int i=0;i<n;i++){
			int f = find(edges[i].from,parent);
			int t = find(edges[i].to,parent);
			if(f != t)
			{ //不在同一集合中
		       Union(f,t,parent);
			   edge_num++;
			   price+=edges[i].weight;
			}
			if(edge_num == m-1) break;
		}
		if(edge_num == m-1) cout<<price<<endl;
		else
			cout<<"?"<<endl;
		
		 
	}
}