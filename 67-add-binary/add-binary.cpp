class Solution {
public:
    string addBinary(string a, string b) 
    {
        if(a.size() < b.size())
            swap(a, b);
        int aa = a.size(), bb = b.size();
        
        int c = 0, r = 0;
        aa --, bb--;
        string ans = "";
        while(bb >= 0)
        {
            r = a[aa] - '0' + b[bb] - '0' + c ;
            c = r/2;
            r = r % 2;
            ans = char(r + '0') + ans;
            aa--, bb--;
        }
        if(aa < 0 && c)
            return '1' + ans;
        while(aa >= 0)
        {
            r = a[aa] - '0' + c;
            c = r/2;
            r = r%2;
            ans = char(r + '0') + ans;
            aa--, bb--;
        }
        if(c)
            return '1' + ans;
        return ans;
    }
};