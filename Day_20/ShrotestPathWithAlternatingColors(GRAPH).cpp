#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        unordered_map<int,list<pair<int,int>>>adj;
        vector<vector<int>>dist(n,vector<int>(2,-1));
        
        for(auto &red:redEdges){
            adj[red[0]].push_back({red[1],0});
        }

        
        for(auto &blue:blueEdges){
            adj[blue[0]].push_back({blue[1],1});
        }

        queue<pair<int,int>>q;
        q.push({0,0});
        q.push({0,1});
        dist[0][0]=dist[0][1]=0;

        while(!q.empty()){
        auto top=q.front();
        q.pop();
        int node=top.first;
        int color=top.second;

        for(auto nbr : adj[node]){
            int neigh=nbr.first;
            int neighColor=nbr.second;
            
            if(color!=neighColor && dist[neigh][neighColor]==-1){
                dist[neigh][neighColor]=dist[node][color]+1;
                q.push({neigh,neighColor});
            }
          }
        }

        vector<int>result(n);

        for(int i=0;i<n;i++){
            if(dist[i][0]==-1)
            result[i]=dist[i][1];

            else if(dist[i][1]==-1)
            result[i]=dist[i][0];

            else
            result[i]=min(dist[i][0],dist[i][1]);
        }
     return result;
    }
};