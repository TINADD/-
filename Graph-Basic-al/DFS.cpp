void Graph::DFS()
{
	//�Ե����Ϸ���  O(V+E) ��Դ�ڵ�1��ʼ����
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
		
		//ͨ���ڽӱ����s�������ڽӵ������
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
