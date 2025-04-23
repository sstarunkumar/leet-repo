class Solution {
public:
    int numRabbits(vector<int>& answers) 
    {
        vector<int> vec(1000);
        for(int &i:answers)
            vec[i]++;
        int ans=0;

        for(int i=0;i<1000;i++)
        {
            int q = i+1;
            ans += (vec[i] / q) * q;
            if(vec[i]%q!=0)
                ans+=q;
        }
        return ans;
    }
};