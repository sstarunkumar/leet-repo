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
    vector< TreeNode * > path;
    bool pathFind(TreeNode *root, int target)
    {
        if(root == nullptr)
            return false;
        if( root -> val == target )
        {
            path.push_back(root);
            return true;
        }
        if(pathFind(root->left, target) || pathFind(root->right, target))
        {
            path.push_back(root);
            return true;
        }
        return false;
    }
    int depth(TreeNode *root)
    {
        if(root == nullptr)
            return 0;
        return max( depth(root->left), depth(root->right) ) + 1;
    }
    int amountOfTime(TreeNode* root, int start) 
    {
        pathFind(root, start);
        int ans = depth( path[0] ) - 1;
        int l = path.size();
        for(int i=1;i<l;i++)
        {
            if( path[i]->right == path[i-1] )
                ans = max( ans, depth( path[i]->left  ) + i );
            else 
                ans = max( ans, depth( path[i]->right ) + i );
        }
        return ans;
    }
};