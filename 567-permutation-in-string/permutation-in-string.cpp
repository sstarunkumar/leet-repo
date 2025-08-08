class Solution {
public:
    bool check(vector<int> &fre,vector<int> &test)
    {
        for(int i=0;i<26;i++)
            if(fre[i]!=test[i])
                return false;
        return true;
    }
    bool checkInclusion(string s1, string s2) 
    {
        if( s1.size() > s2.size() )
            return false;
        int a = s1.size();
        vector<int> fre(26,0);
        for(char &ch : s1)
            fre[ ch-'a' ]++;
        int n = s2.size();  
        vector<int> test(26,0);
        for(int i=0;i<a;i++)
            test[ s2[i]-'a' ]++;
        if(check(fre,test))
            return true;
        for(int i=a;i<n;i++)
        {
            test[ s2[i]-'a' ]++;
            test[ s2[i-a]-'a' ]--;
            if(check(fre,test))
                return true;
        }
        return false;
    }
};