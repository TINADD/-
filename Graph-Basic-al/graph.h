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

class Graph {
public:
	int V;
	vector<vector<int>>  adjac_mat; //�ڽӾ���
	vector<node *> adjac_tab;//�ڽӱ�

	void init_graph(string filename); //��ʼ��ͼ
	void BFS(); //�����������
	void DFS();//�����������
};

#endif // ! GRAPH_H

