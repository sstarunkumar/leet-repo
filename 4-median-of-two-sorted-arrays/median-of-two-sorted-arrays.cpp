class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int n=nums1.size();
        int m=nums2.size();
        if(n>m)
            return findMedianSortedArrays(nums2,nums1);
        int low,high;
        low = 0,high = n;
        while(low<=high)
        {
            /*
            1 2 3 4 5 6 
             5 6 7 8 9 10
            */
            int mid1 = (low + high)/2;
            int mid2 = (m+n+1)/2 - mid1;

            int left1 = mid1 == 0 ? INT_MIN: nums1[mid1-1];
            int right1 = mid1 == n ? INT_MAX:nums1[mid1];
            int left2 = mid2 == 0 ? INT_MIN: nums2[mid2-1];
            int right2 = mid2 == m ? INT_MAX:nums2[mid2];
            if(left1 <= right2 && left2 <= right1 )
            {
                if ( (m+n)&1 )
                {
                    return (double)max(left1,left2);
                }
                else
                {
                    return (double)( max(left1,left2) + min(right1,right2) )/2.0;
                }

            }
            else if(left1 > right2)
            {
                high = mid1-1;
            }
            else
                low = mid1+1;
        }
        return 0;
    }
};