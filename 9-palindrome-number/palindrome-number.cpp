class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x < 0)
            return false;
        string s = to_string(x);
        int size = s.size();
        int i = 0, j = size -1;
        while(i<j)
        {
            if(s[i] != s[j])
                return false;
            j--;
            i++;
        }
        return true;
    }
};