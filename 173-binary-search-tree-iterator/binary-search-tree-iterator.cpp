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
class BSTIterator {
public:
    queue<int> q;
    BSTIterator(TreeNode* root) {
        pushtoq(root);
    }
    void pushtoq(TreeNode* root)
    {
        if(root == nullptr)
            return ;
        pushtoq(root->left);
        q.push(root->val);
        pushtoq(root->right);
    }
    int next() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */