class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) 
    {
        int n = fruits.size();
        double s = sqrt(n);
        int windowsize = s;
        if( s - windowsize != 0 )
            windowsize ++;
        vector<int> windowmax( windowsize );
        for(int i=0;i<windowsize;i++)
        {
            int start = i * windowsize, maxi = 0;
            for( int j=0;j < windowsize && start + j < n ;j++ )
                maxi = max( maxi,baskets[ start+j ] );
            windowmax[i] = maxi;
        }
        int ans = n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<windowsize;j++)
            {
                if( fruits[i] <= windowmax[j] )
                {
                    ans--;
                    int start = j * windowsize, maxi = 0;
                    int x = 0;
                    for(     ;x<windowsize && start+x < n;x++)
                    {
                        if( fruits[i] <= baskets[start+x] )
                        {
                            baskets[ start+x ] = 0;
                            break;
                        }
                        maxi = max( maxi,baskets[start+x] );
                    }

                    for(    ;x<windowsize && start + x < n ; x++)
                        maxi = max( maxi,baskets[start+x] );
                    windowmax[j] = maxi;
            
                    break;
                }
            }
        }
        return ans;
    }
};