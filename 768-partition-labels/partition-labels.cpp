class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        vector<int> ind(26,0);
        int n= s.size();
        for(int i=0;i<n;i++)
            ind[s[i]-'a'] = i;
        vector<int> ans;
        int maxi = 0;
        int x = 0;
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi,ind[s[i]-'a']);
            if(maxi == i)
            {
                ans.push_back(maxi+1-x);
                x += maxi+1-x;
            }
        }
        return ans;
    }
};