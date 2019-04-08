/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) 
	{
        if(root==NULL) return 0;
		if(root->left==NULL)
			return maxDepth(root->right)+1;
		if(root->right==NULL)
			return maxDepth(root->left)+1;
		int Ldeep=maxDepth(root->left);
		int Rdeep=maxDepth(root->right);
		return max(Ldeep,Rdeep)+1;
    }
};