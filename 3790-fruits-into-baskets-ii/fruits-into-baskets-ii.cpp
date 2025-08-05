class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) 
    {
        int n = fruits.size() , ans = 0;
        vector<bool> occupancy(n,true);
        for(int i=0;i<n;i++)
        {
            int j;
            for(j=0;j<n;j++)
            {
                if( occupancy[j] && fruits[i] <= baskets[j] )
                {
                    occupancy[j] = false;
                    break;
                }
            }
            if( j==n )
                ans ++;
        }
        return ans;
    }
};