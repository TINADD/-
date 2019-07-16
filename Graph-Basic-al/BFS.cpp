/*图的广度优先搜索*/
/*
思路：
读文件，生成图，用邻接矩阵表示。
从源节点s开始
首先判断当前结点有没有被访问过，如果没有就输出当前结点，并将当前结点标记为已访问，同时将该结点的所有未访问过的邻接结点入队列。 
判断队列是否为空，如果非空，访问头结点并pop ，标记头结点已访问，并将当前结点所有未访问过的邻接结点入队列。
队列为空就返回 。 
*/ 

void Graph::BFS()
{
	//广度优先遍历图,从源节点1开始
	vector<bool> is_visited(V+1,false); 
	queue<int> q;
	int s = 1;
	cout << s << " ";
	is_visited[s] = true;
	//通过邻接矩阵将结点s的所有邻接点入队列
	/*for (int n=1;n<V+1;++n) 
	{
		if (adjac_mat[s][n] && !is_visited[n])
		{
			q.push(n);
			is_visited[n] = true;
		}
	}*/
	//通过邻接表将结点s的所有邻接点入队列
	node *head = adjac_tab[s]->next;
	while (head) 
	{
		if (!is_visited[head->val])
		{
			q.push(head->val);
			is_visited[head->val] = true;
		}
		head = head->next;
	}
	while (!q.empty()) 
	{
		s = q.front();
		q.pop();
		cout << s << " ";
		is_visited[s] = true;
		//通过邻接矩阵将结点s的所有邻接点入队列
		/*for (int n = 1; n < V + 1; ++n)
		{
			if (adjac_mat[s][n] && !is_visited[n])
			{
				q.push(n);
				is_visited[n] = true;
			}
		}*/
		//通过邻接表将结点s的所有邻接点入队列
		node *head = adjac_tab[s]->next;
		while (head)
		{
			if (!is_visited[head->val])
			{
				q.push(head->val);
				is_visited[head->val] = true;
			}
			head = head->next;
		}
	}
}

