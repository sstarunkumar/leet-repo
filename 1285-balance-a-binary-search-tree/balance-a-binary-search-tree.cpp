/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<int> vec;
    void inorder(TreeNode *root)
    {
        if( !root )
            return;
        inorder(root->left);
        vec.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* tree(int lo, int hi)
    {
        if(lo > hi)
            return nullptr;
        int mid = lo + (hi - lo)/2;
        TreeNode *temp = new TreeNode(vec[mid]);
        temp->left = tree(lo, mid-1);
        temp->right = tree(mid+1, hi);
        return temp;
    }
    TreeNode* balanceBST(TreeNode* root) 
    {
        vec.clear();
        inorder(root);
        int lo = 0, hi = vec.size()-1;
        return tree(lo, hi);
    }
};