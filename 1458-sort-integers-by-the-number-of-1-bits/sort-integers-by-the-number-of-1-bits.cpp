class Solution {
public:
    int setbits(int a)
    {
        int c = 0;
        while(a != 0)
        {
            c++;
            a = a&(a-1);
        }
        return c;
    }
    bool compare(int a,int b)
    {
        int aa = setbits(a);
        int bb = setbits(b);
        //setbits then value
        if( aa < bb )
            return true;
        else if( aa > bb )
            return false;
        else
            return a < b;
    }
    vector<int> sortByBits(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end(),[&](int a,int b)
        {
            return compare(a,b);
        }
        );
        return arr;
    }
};