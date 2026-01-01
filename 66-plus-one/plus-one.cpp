class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int n = digits.size();
        digits[n-1] ++;
        if(digits[n-1] <= 9)
            return digits;
    
        digits[n-1] = 0;

        int i = n-2;
        while(i >= 0)
        {
            digits[i] ++;
            if(digits[i] <= 9)
                return digits;
            digits[i] = 0;
            i--;
        }

        if(i == -1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};