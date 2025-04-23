class Solution {
public:
    int sum(int n)
    {
        int ans=0;
        while(n>0)
        {
            ans+=n%10;
            n/=10;
        }
        return ans;
    }
    int countLargestGroup(int n) 
    {
        vector<int> vec(37,0);
        for(int i=1;i<=n;i++)
            vec[sum(i)]++;
        int count = 0;
        int maxi = *max_element(vec.begin(),vec.end());
        for(int &i:vec)
            if(i==maxi)
                count++;
        return count;
    }
};