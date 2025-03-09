class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) 
    {
        colors.insert(colors.end(),colors.begin(),colors.begin()+k-1);
        int n=colors.size();
        int count=0;
        int left=0;
        for(int right=1;right < n;right++)
        {
            if(colors[right] == colors[right-1])
                left=right;
            if(right-left+1 >= k)
                count++;
        }
        return count;
    }
};