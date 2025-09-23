class Solution {
public:
    vector<string> words(string st)
    {
        vector<string> ans;
        stringstream ss(st);
        char del = '.';
        string temp;
        while( getline(ss,temp,del) )
            ans.push_back(temp);
        return ans;
    }
    int compareVersion(string version1, string version2) 
    {
        vector<string> v1 = words(version1);
        vector<string> v2 = words(version2);
        int a = v1.size(), b = v2.size();
        int m = max(a,b);
        int u,v;
        for(int i=0;i<m;i++)
        {
            u = i < a ? stoi(v1[i]) : 0;
            v = i < b ? stoi(v2[i]) : 0;
            if(u > v)
                return 1;
            else if(u < v)
                return -1;
        }
        return 0;
    }
};