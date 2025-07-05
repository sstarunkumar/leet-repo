class Solution {
public:
    int findLucky(vector<int>& arr) 
    {
        map<int,int> mp;
        for(int &i : arr)
            mp[i] ++;
        for(auto i=mp.rbegin();i!=mp.rend();i++)
            if(i->first == i->second)
                return i->first;
        return -1;
    }
};