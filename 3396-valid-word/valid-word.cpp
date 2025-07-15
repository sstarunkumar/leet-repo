class Solution {
public:
    bool isvowel(char ch)
    {
        if(ch < 96)
            ch = ch ^ (1<<5);
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }
    bool isValid(string word) 
    {
        int n = word.size();
        if(n<3)
            return false;
        bool v = false,c = false;
        for(int i=0;i<n;i++)
        {
            if( isdigit(word[i]) )
            {}
            else if( isalpha(word[i]) )
            {
                if( isvowel(word[i]) )
                    v = true;
                else
                    c = true;
            }
            else
                return false;
        }
        return v && c ;
    }
};