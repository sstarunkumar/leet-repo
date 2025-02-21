class Solution {
public:
    string convert(string s, int n) 
    {
        vector<vector<char>> vec(n);
        int k=0;
        while(k<s.size())
        {
            for(int i=0;i<n && k<s.size();i++)
                vec[i].push_back(s[k++]);
            for(int i=n-2;i>=1 && k<s.size();i--)
                vec[i].push_back(s[k++]);
        }
        string st="";
        for(int i=0;i<n;i++)
            for(char j:vec[i])
                st+=j;
        return st;

    }
};