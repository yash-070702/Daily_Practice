#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    unordered_map<int,list<int>>adj;
    vector<bool>visited;
    int count=0;

    void dfs(int node,int &edgeCount , int &vertexCount){
        visited[node]=true;

        vertexCount++;

        for(int nbr : adj[node]){
            edgeCount++;

            if(!visited[nbr])
            dfs(nbr,edgeCount,vertexCount);
        }

    }
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        visited.assign(n,false);


        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for(int i=0;i<n;i++){
            if(!visited[i]){
                int edgeCount=0;
                int vertexCount=0;
                dfs(i,edgeCount,vertexCount);

                if(edgeCount==((vertexCount)*(vertexCount-1)))
                count++;
            }
        }
        return count;
    }
};