#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

/*
ͼ����Ŵ�1��ʼ
����ͼG=<V,E>
*/
class node {
public:
	int val;
	int dis;
	node *next;

	node();
	node(int v);
	node(int v, int d);
};

class Graph{
public:
	int V;
	vector<vector<int>>  adjac_mat; //�ڽӾ���
	vector<node *> adjac_tab;//�ڽӱ�

	void init_graph(string filename); //��ʼ��ͼ
	void BFS();
};

void Graph::init_graph(string filename)
{
	fstream fin(filename,ios::in);
	string s;
	getline(fin,s);
	stringstream sst;
	sst << s;
	sst >> V;
	adjac_mat = vector<vector<int>>(V+1,vector<int>(V+1,0));
	adjac_tab = vector<node *>(V+1);
	sst.clear();
	sst.str("");
	for (int i = 1; i < V + 1; ++i)
	{
		adjac_tab[i] = new node(i);
	}
	while (getline(fin,s)) 
	{
		int e1 = 0, e2 = 0, dis = 0;
		sst << s;
		sst >> e1>>e2;
		sst.clear();
		sst.str("");
		//�����ڽӾ��� 
		adjac_mat[e1][e2] = adjac_mat[e2][e1] = 1;
		//�����ڽӱ� 
		node *tmp1 = new node(e1);
		node *tmp2 = new node(e2);
		tmp2->next = adjac_tab[e1]->next;
		adjac_tab[e1]->next = tmp2;
		tmp1->next = adjac_tab[e2]->next;
		adjac_tab[e2]->next = tmp1;
	}
}

