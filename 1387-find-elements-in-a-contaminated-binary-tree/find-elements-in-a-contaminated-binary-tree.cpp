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
class FindElements 
{
public:
    set<int> se;
    void valfill(TreeNode* root,int num)
    {
        if(!root)
            return ;
        root->val=num;
        se.insert(num);
        valfill(root->left,num*2+1);
        valfill(root->right,num*2+2);
    }
    FindElements(TreeNode* root) 
    {
        valfill(root,0);
    }
    bool find(int target) 
    {
        return se.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */