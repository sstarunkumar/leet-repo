class Solution {
public:
    bool isvowel(char c)
    {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ;
    }
    long long countOfSubstrings(string word, int k)
    {
        return atleastk(word,k-1) - atleastk(word,k);
    }
    long long atleastk(string &word,int k)
    {
        int n=word.size();
        long long ans=0;
        unordered_map<char,int> mp;
        int left=0,consonents=0;
        for(int right=0;right<n;right++)
        {
            if( isvowel(word[right]) )
                mp[word[right]] ++;
            else
                consonents++;
            while(mp.size()==5 && consonents > k)
            {
                ans += n-right;
                if(isvowel(word[left]))
                {
                    mp[word[left]]--;
                    if(mp[word[left]]==0)
                        mp.erase(word[left]);
                }
                else
                    consonents--;
                left++;
            }
        }
        return ans;
    }
};