class Solution {
public:
    bool isVowel(char c)
    {
        c = c | (1<<5);
        if( c == 'a' || c == 'e' || c == 'i' || c == 'o' ||c == 'u' )
            return true;
        return false;
    }
    string sortVowels(string s) 
    {
        int n = s.size();
        int count = 0;
        vector<bool> boo(n,false);
        for(int i=0;i<n;i++)
        {
            boo[i] = isVowel(s[i]);
            count += boo[i];
        }
        string str(count,' ');
        int j=0;
        for(int i=0;i<n;i++)
            if(boo[i])
                str[j++] = s[i];
        j=0;
        sort(str.begin(),str.end());
        for(int i=0;i<n;i++)
            if(boo[i])
                s[i] = str[j++];
        return s;
    }
};