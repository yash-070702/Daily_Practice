#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int ans=INT_MAX;
    vector<bool>vis;
    unordered_map<int,list<pair<int,int>>>adj;

    void dfs(int node){
        vis[node]=true;

        for(auto nbr : adj[node]){
            ans=min(ans,nbr.second);
            if(!vis[nbr.first]){
                dfs(nbr.first);
            }
        }
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
      
      vis.assign(n+1,false);
      

      for(auto &road :roads){
        int u=road[0];
        int v=road[1];
        int dis=road[2];
        
        adj[u].push_back({v,dis});
        adj[v].push_back({u,dis});
      }

      dfs(1);

      return ans;

    }
};