/*ͼ�Ĺ����������*/
/*
˼·��
���ļ�������ͼ�����ڽӾ����ʾ��
��Դ�ڵ�s��ʼ
�����жϵ�ǰ�����û�б����ʹ������û�о������ǰ��㣬������ǰ�����Ϊ�ѷ��ʣ�ͬʱ���ý�������δ���ʹ����ڽӽ������С� 
�ж϶����Ƿ�Ϊ�գ�����ǿգ�����ͷ��㲢pop �����ͷ����ѷ��ʣ�������ǰ�������δ���ʹ����ڽӽ������С�
����Ϊ�վͷ��� �� 
*/ 

void Graph::BFS()
{
	//������ȱ���ͼ,��Դ�ڵ�1��ʼ
	vector<bool> is_visited(V+1,false); 
	queue<int> q;
	int s = 1;
	cout << s << " ";
	is_visited[s] = true;
	//ͨ���ڽӾ��󽫽��s�������ڽӵ������
	/*for (int n=1;n<V+1;++n) 
	{
		if (adjac_mat[s][n] && !is_visited[n])
		{
			q.push(n);
			is_visited[n] = true;
		}
	}*/
	//ͨ���ڽӱ����s�������ڽӵ������
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
		//ͨ���ڽӾ��󽫽��s�������ڽӵ������
		/*for (int n = 1; n < V + 1; ++n)
		{
			if (adjac_mat[s][n] && !is_visited[n])
			{
				q.push(n);
				is_visited[n] = true;
			}
		}*/
		//ͨ���ڽӱ����s�������ڽӵ������
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

