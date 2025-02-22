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
class Solution 
{
public:
    TreeNode* recoverFromPreorder(string str) 
    {
        int i=0;
        string number="";
        int height=0;
        while(i<str.size() && str[i]!='-')
        {
            number+=str[i];
            i++;
        }
        int x=stoi(number);
        TreeNode *root = new TreeNode(x);
        stack<TreeNode*> st;
        st.push(root);
        cout<<x<<" "<<height<<endl;

        while(i<str.size())
        {
            number="";
            height=0;
            while(i<str.size() && str[i]=='-')
            {
                i++;
                height++;
            }
            while(i<str.size() && str[i]!='-')
            {
                number+=str[i];
                i++;
            }
            x=stoi(number);
            while(st.size() > height)
                st.pop();
            if(st.top()->left == nullptr)
            {
                st.top()->left = new TreeNode(x);
                st.push( st.top()->left );
            }
            else
            {
                st.top()->right = new TreeNode(x);
                st.push( st.top()->right );
            }
            cout<<x<<" "<<height<<endl;
        }
        return root;
    }
};