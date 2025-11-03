class Solution {
public:
    int minCost(string colors, vector<int>& need) 
    {
        int n = colors.size();
        if(n == 1)
            return 0;
        int i = 0, j = 1, sum = 0;
        while( j<n )
        {
            if( colors[i] == colors[j] )
            {
                if(need[i] <= need[j])
                {
                    sum += need[i];
                    i = j;
                    j++;
                }
                else
                {
                    sum += need[j];
                    j++;
                }
            }
            else
            {
                i = j;
                j++;
            }
        } 
        return sum;
    }
};