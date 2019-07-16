/*
class ListNode{
int val;
ListNode *left;
ListNode *right;
};
*/

ListNode * preOrder(ListNode *root)
{
	ListNode *rc = root,pre= NULL;
	stack<ListNode*> line;
	while(rc || !line.empty())
	{
		if(rc)
		{
			line.push(rc);
			rc = rc->left;
		}else
		{
			rc = line.top();
			if(rc->right && rc->right != pre)
				rc = rc->right;
			else
				visit(rc);
			    pre = rc;
				line.pop();
				rc = NULL;
		}
		
	}
	
}