class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) 
    {
        int sum = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end(), 
            [&](int a, int b)
            {
                return a > b;
            }
        );
        int n = capacity.size();
        for(int i=0;i<n;i++)
        {
            if(sum <= 0)
                return i;
            sum -= capacity[i];
        }
        if(sum > 0)
            return -1;
        return n;
    }
};