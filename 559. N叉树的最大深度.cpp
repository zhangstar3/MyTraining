
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution 
{
public:
    int maxDepth(Node* root) 
	{
		if(root==NULL) return 0;
		int res=1;
		int n=root->children.size();
		for(vector<Node*>::iterator it=root->children.begin();it!=root->children.end();++it)
		{
			res=max(res,maxDepth(*it)+1);
		}
		return res;
    }
};