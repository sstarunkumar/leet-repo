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
    TreeNode *ans;
    int maxi = 0;
    int depth(TreeNode *root, int level)
    {
        if(root == nullptr)
            return 0;

        maxi = max(maxi, level);
        int left = depth(root->left, level + 1);
        int right = depth(root->right, level + 1);
        int m = max(left, right);

        if(left == right)
        {
            if( level + m == maxi )
                ans = root;
        }
        return m + 1;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) 
    {
        ans = root;
        depth(root, 0);
        return ans;
    }
};