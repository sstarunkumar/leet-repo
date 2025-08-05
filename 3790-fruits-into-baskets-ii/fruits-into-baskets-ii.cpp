class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) 
    {
        int n = fruits.size() , ans = n;
        for(int i=0;i<n;i++)
        {
            int j;
            for(j=0;j<n;j++)
            {
                if( fruits[i] <= baskets[j] )
                {
                    baskets[j] = 0;
                    ans--;
                    break;
                }
            }
        }
        return ans;
    }
};