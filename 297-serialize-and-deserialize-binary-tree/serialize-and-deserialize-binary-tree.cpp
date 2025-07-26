/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string str;
    int ind;
    string serialize(TreeNode* root) 
    {
        str = "";
        formstring(root,str);
        cout<<str<<endl;
        return str;
    }
    void formstring(TreeNode *root,string &s)
    {
        if(root == nullptr)
        {
            s+="* ";
            return ;
        }
        s += to_string(root->val) + " ";
        formstring(root->left,s);
        formstring(root->right,s);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        vector<string> vec;
        stringstream bot(data);
        string iter;
        while( bot >> iter )
            vec.push_back(iter);
        TreeNode *root = nullptr;
        int n = vec.size();
        int ind = 0;
        root = construct(vec,ind);
        return root;
    }
    TreeNode *construct(vector<string> &vec,int &ind)
    {
        if(vec[ind] == "*")
        {
            ind++;
            return nullptr;
        }
        TreeNode *root = new TreeNode( stoi( vec[ind++] ) );
        root->left = construct(vec,ind);
        root->right = construct(vec,ind);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));