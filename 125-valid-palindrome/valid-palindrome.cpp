class Solution {
public:
    bool ispalin(string &s,int i,int j)
    {
        while(!isalnum(s[i]) && i<j)
            i++;
        while(!isalnum(s[j]) && j>i)
            j--;
        if(i>=j)
            return true;
        s[i]|=(1<<5);
        s[j]|=(1<<5);
        cout<<s[i]<<" "<<s[j]<<endl;
        if(s[i]!=s[j])
            return false;
        return ispalin(s,i+1,j-1);
    }
    bool isPalindrome(string s) 
    {
        return ispalin(s,0,s.size()-1);
    }
};