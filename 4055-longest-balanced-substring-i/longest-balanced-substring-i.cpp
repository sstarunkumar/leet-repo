class Solution {
public:
    int longestBalanced(string s) 
    {
        int n = s.size();
        vector<int> vec(n);

        auto it = s.begin();
        for(int &i : vec)
            i = *it++ - 97;
        
        int ans = 0;
        vector<int> count(26, 0);
        for(int i=0;i<n;i++)
        {
            fill( count.begin(), count.end(), 0 );
            int unique = 0, maxi = 0;
            for(int j=i;j<n;j++)
            {
                count[ vec[j] ]++;
                int fre = count[ vec[j] ];
                int l = j-i+1;
                maxi = max(maxi, fre);
                if( fre == 1 )
                    unique++;
                if(maxi * unique == l)
                    ans = max(ans, l);
            }
        }
        return ans;
    }
};