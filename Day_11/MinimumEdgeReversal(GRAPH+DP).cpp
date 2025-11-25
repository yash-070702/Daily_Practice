#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    unordered_map<int,list<pair<int,int>>>adj;
    vector<int>vist;
    vector<int>res;


    int dfs1(int node){
        vist[node]=1;

        int cost=0;

        for(auto nbr : adj[node]){
            int v=nbr.first;
            int wt=nbr.second;

            if(!vist[v]){
                cost+=(wt+dfs1(v));
            }
        }
        return cost;
    }

    void dfs2(int node){
        vist[node]=1;

        for(auto nbr : adj[node]){
            int v=nbr.first;
            int wt=nbr.second;

            if(!vist[v]){
                if(wt==0){
                    res[v]=res[node]+1;
                }
                else{
                    res[v]=res[node]-1;
                }
                dfs2(v);
            }
        }
    }
    
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
    res.assign(n,0);
    vist.assign(n,0);

    for(auto edge : edges){
        int u=edge[0];
        int v=edge[1];

        adj[u].push_back({v,0});
        adj[v].push_back({u,1});
    }
        res[0]=dfs1(0);

        fill(vist.begin(),vist.end(),0);

        dfs2(0);

        return res;

    }
};