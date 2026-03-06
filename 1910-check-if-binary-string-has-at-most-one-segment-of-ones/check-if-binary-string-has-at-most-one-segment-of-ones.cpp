class Solution {
public:
    bool checkOnesSegment(string s) 
    {
        bool one = false, zero = false;
        for(char &ch : s)
        {
            if(ch == '1')
            {
                if(zero)
                    return false;
                one = true;
            }
            else
            {
                if(one)
                    zero = true;
            }
        }
        return true;
    }
};