#pragma once
#ifndef  GRAPH_H
#define  GRAPH_H

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
/*
图结点编号从1开始
无向图G=<V,E>
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

class Graph {
public:
	int V;
	vector<vector<int>>  adjac_mat; //邻接矩阵
	vector<node *> adjac_tab;//邻接表

	void init_graph(string filename); //初始化图
	void BFS(); //广度优先搜索
	void DFS();//深度优先搜索
};

#endif // ! GRAPH_H

