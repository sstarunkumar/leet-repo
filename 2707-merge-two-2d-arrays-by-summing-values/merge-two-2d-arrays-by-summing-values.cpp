class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) 
    {
        int a=0;
        int b=0;
        vector<vector<int>> vec;
        while(a < nums1.size() && b < nums2.size())
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
        while(a < nums1.size())
        {
            vec.push_back( {nums1[a][0] , nums1[a][1]} );
            a++;
        }
        while(b < nums2.size())
        {
            vec.push_back( {nums2[b][0],nums2[b][1]} );
            b++;
        }
        return vec;
    }
};