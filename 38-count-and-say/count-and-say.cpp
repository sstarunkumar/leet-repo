class Solution {
public:
    string compress(string str)
    {
        string s = "";
        int count = 1;
        char prev = str[0];
        int n = str.size();
        for(int i=1;i<n;i++)
        {
            if(prev == str[i])
                count++;
            else
            {
                s+=to_string(count)+prev;
                count = 1;
                prev = str[i];
            }
        }
        s+=to_string(count)+prev;
        return s;
    }
    string countAndSay(int n) 
    {
        if(n==1)
            return "1";
        return compress(countAndSay(n-1));
    }
};