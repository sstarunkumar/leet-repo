class Solution {
public:
    void dfs(vector<vector<pair<int,int>>> &vec,vector<bool> &vis,vector<int> &parent,int mp,int curr,int &andand)
    {
        vis[curr] = true;
        parent[curr] = mp;
        for(auto i:vec[curr])
            andand &= i.second;
        for(auto i:vec[curr])
            if(!vis[i.first])
                dfs(vec,vis,parent,mp,i.first,andand);
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) 
    {
        vector<vector<pair<int,int>>> vec(n);
        int x=edges.size();
        for(int i=0;i<x;i++)
        {
            vec[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            vec[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<bool> vis(n,false);
        vector<int> parent(n,INT_MIN);
        vector<int> minand(n);
        x=query.size();
        vector<int> bot;
        for(int i=0;i<x;i++)
        {
            if(parent[query[i][0]] == INT_MIN)
            {
                int andand = INT_MAX;
                dfs(vec,vis,parent,query[i][0],query[i][0],andand);
                for(int p=0;p<n;p++)
                {
                    if(parent[p] == query[i][0])
                        minand[p] = andand;
                }
            }
            if( parent[ query[i][0] ] == parent[ query[i][1] ])
                bot.push_back(minand[ query[i][0] ]);
            else
                bot.push_back(-1);
        }
        return bot;
    }
};