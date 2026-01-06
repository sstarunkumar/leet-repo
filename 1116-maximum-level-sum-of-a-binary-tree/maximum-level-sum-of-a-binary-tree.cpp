class Solution 
{
public:
    int maxLevelSum(TreeNode* root) 
    {
        int maxi = INT_MIN;
        queue<TreeNode*> q;

        q.push(root);
        int k = 1, ans = 1;
        while( !q.empty() )
        {
            int s = q.size();
            int sum = 0;
            while(s--)
            {
                TreeNode *p = q.front();
                q.pop();

                sum += p->val;
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
            }
            if(sum > maxi)
            {
                maxi = sum;
                ans = k;
            }
            k++;
        }
        return ans;
    }
};