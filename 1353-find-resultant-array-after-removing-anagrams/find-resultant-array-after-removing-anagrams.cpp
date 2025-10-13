class Solution 
{
public:
    bool isAnagram(string &a,string &b)
    {
        if(a.size() != b.size())
            return false;
        int v;
        vector<int> chars(26,0);
        for(char ch:a)
            chars[ ch-'a' ]++;
        for(char ch:b)
        {
            v = ch - 'a';
            chars[v]--;
            if(chars[v] < 0)
                return false;
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) 
    {
        int left = 0;
        int n = words.size();
        vector<string> ans;
        for(int i=1;i<n;i++)
        {
            if( !isAnagram(words[i], words[left]) )
            {
                ans.push_back(words[left]);
                left = i;
            }
        }
        ans.push_back(words[left]);
        return ans;
    }
};