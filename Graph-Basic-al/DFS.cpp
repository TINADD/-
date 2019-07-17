void Graph::DFS()
{
	//自底向上访问  O(V+E) 从源节点1开始访问
	vector<bool> is_visited(V+1,false);
	stack<int> st;
	int s = 1;
	st.push(s);
	while (!st.empty()) 
	{
		s = st.top();
		if (!is_visited[s])
		{
			cout << s << "	";
			is_visited[s] = true;
		}
		st.pop();
		
		//通过邻接表将结点s的所有邻接点入队列
		node *head = adjac_tab[s]->next;
		while (head)
		{
			if (!is_visited[head->val])
			{
				st.push(head->val);
			}
			head = head->next;
		}
	}
}
