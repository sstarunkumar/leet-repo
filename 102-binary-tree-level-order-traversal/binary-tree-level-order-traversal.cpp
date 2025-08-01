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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(root == nullptr)
            return {};
        vector<vector<int>> big;
        queue<TreeNode*> q;
        q.push(root);
        while( !q.empty() )
        {
            vector<int> vec;
            int ss = q.size();
            while(ss--)
            {
                TreeNode * x = q.front();
                vec.push_back(x->val);
                q.pop();
                if( x->left )
                    q.push(x->left);
                if( x-> right )
                    q.push(x->right);
            }
            big.push_back(vec);
        }    
        return big;
    }
};