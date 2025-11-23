#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    unordered_map<int,list<int>>adj;
    unordered_map<int,bool>visited;
    vector<int>disc;
    vector<int>low;
    vector<pair<int,int>>result;
    int timer;
    int n;
    
    void solve(int node,int parent){
        timer++;
        disc[node]=low[node]=timer;
        visited[node]=true;
        
        for(int nbr : adj[node]){
            if(parent==nbr)
            continue;
            
            else if(!visited[nbr]){
                solve(nbr,node);
                low[node]=min(low[nbr],low[node]);
                
                if(low[nbr]>disc[node])
                result.push_back({nbr,node});
            }
            else
            low[node]=min(low[node],disc[nbr]);
        }
    }
    
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
      
    n=V;
    disc.resize(n);
    low.resize(n);
    timer=0;
    int node=0;
    int parent=-1;
    
    for(auto edge : edges){
        int u=edge[0];
        int v=edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                solve(i, -1);
            }
        }

    
    
    
    for(auto r : result){
        if((c==r.first && d==r.second) || (c==r.second && d==r.first))
        return true;
    }
    return false;
    }
};