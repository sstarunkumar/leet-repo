class Solution {
public:
    bool check(vector<int> &text,vector<int> &pattern)
    {
        for(int i=0;i<58;i++)
            if( text[i] < pattern[i] )
                return false;
        return true;
    }
    string minWindow(string s, string t) 
    {
        int left = 0,n = s.size();
        vector<int> pattern(58,0), text(58,0);
        for( char &ch : t )
            pattern[ ch-'A' ] ++;
        int ans = INT_MAX,start = -1;
        for(int i=0;i<n;i++)
        {
            text[ s[i]-'A' ]++;
            while( check(text,pattern) )
            {
                if( i-left+1 < ans )
                {
                    start = left;
                    ans = i-left+1;
                }
                text[ s[left] - 'A' ] --;
                left++;
            }
        } 
        if(ans==INT_MAX)
            return "";
        return s.substr( start,ans );
    }
};