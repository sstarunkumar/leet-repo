class Solution {
public:
    bool valid( unordered_map<char,int> &mp )
    {
        int x = mp.begin()->second;
        for(auto i = mp.begin(); i != mp.end(); i++)
        {
            if( i->second != x )
                return false;
        }
        return true;
    }
    int longestBalanced(string s) 
    {
        int l = s.size();
        int ans = 0;
        unordered_map<char, int> mp;
        for(int i=0;i<l;i++)
        {
            mp.clear();
            for(int j=i;j<l;j++)
            {
                mp[ s[j] ] ++;
                if( valid(mp) )
                    ans = max(ans, j - i + 1);
            }
        }    
        return ans;
    }
};