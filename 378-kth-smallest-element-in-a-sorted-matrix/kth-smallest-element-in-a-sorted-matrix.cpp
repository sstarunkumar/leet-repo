class Solution {
public:
    int lessthan(vector<int> &vec,int c,int k)
    {
        int ans = -1;
        int lo = 0, hi = c-1;
        while( lo <= hi )
        {
            int mid = lo + (hi-lo)/2;
            if(vec[mid] < k)
            {
                ans = mid;
                lo = mid+1;
            }
            else
                hi = mid-1;
        }
        return ans+1;
    }
    int novals(vector<vector<int>> &matrix,int r,int c,int mid)
    {
        //for each row find no. of columns ;
        int ans = 0;
        for(int i=0;i<r;i++)
        {
            int cols = lessthan(matrix[i],c,mid);
            if( !cols )
                break;
            ans += cols;
        }
        return ans;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        int r = matrix.size();
        int c = matrix[0].size();

        int lo = matrix[0][0], hi = matrix[r-1][c-1];
        while(lo <= hi)
        {
            int mid = lo + (hi-lo)/2;
            int left = novals(matrix,r,c,mid);

            if(left >= k)
                hi = mid-1;
            else
                lo = mid+1;
        } 
        return hi;   
    }
};