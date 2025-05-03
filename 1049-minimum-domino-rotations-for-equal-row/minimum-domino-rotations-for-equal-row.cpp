class Solution {
public:
    int check(int k,vector<int> &tops,vector<int> &bottoms)
    {
        int n = tops.size();
        int cont=0,cnt=0;
        for(int i=0;i<n;i++)
            if(tops[i]!=k && bottoms[i]!=k)
                return -1;
        else if(tops[i] != k)
            cnt++;
        else if(bottoms[i] != k)
            cont++;
        return min(cont,cnt);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) 
    {
        int x = check(tops[0],tops,bottoms);
        if(x!=-1)
            return x;
        else 
            return check(bottoms[0],tops,bottoms);
    }
};