class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) 
    {
        int a=0;
        int b=0;
        int one=nums1.size();
        int two = nums2.size();
        vector<vector<int>> vec;
        while(a < one && b < two)
        {
            if(nums1[a][0] < nums2[b][0])
            {
                vec.push_back( {nums1[a][0] , nums1[a][1]} );
                a++;
            }
            else if(nums1[a][0] > nums2[b][0])
            {
                vec.push_back( {nums2[b][0],nums2[b][1]} );
                b++;
            }
            else
            {
                vec.push_back( {nums1[a][0],nums1[a][1]+nums2[b][1]} );
                a++;
                b++;
            }
        }
        while(a < one)
        {
            vec.push_back( {nums1[a][0] , nums1[a][1]} );
            a++;
        }
        while(b < two)
        {
            vec.push_back( {nums2[b][0],nums2[b][1]} );
            b++;
        }
        return vec;
    }
};