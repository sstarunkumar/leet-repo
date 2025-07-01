class Solution {
public:
    int possibleStringCount(string word) 
    {
        int n = word.size();
        char ch = word[0];
        int count =1;
        int ans = 1;
        for(int i=1;i<n;i++)
        {
            if(ch == word[i])
                count ++;
            else
            {
                ans += count -1;
                count = 1;
                ch = word[i];
            }
        } 
        ans += count -1;
        return ans;  
    }
};