#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<int>parent;
    vector<int>rank;

    static bool cmp(vector<int>&a, vector<int>&b){
        if(a[0]==b[0])
        return a[3]<b[3];

        return a[0]<b[0];
    }
 
    int findParent(int node ){
        if(parent[node]==node)
        return node;

        else
        return parent[node]=findParent(parent[node]);
    }

    void makeUnion(int u , int v){
        u=findParent(u);
        v=findParent(v);

        if(rank[u]<rank[v])
        parent[u]=v;

        else if(rank[v]<rank[u])
        parent[v]=u;

        else{
            parent[v]=u;
            rank[u]++;
        }
    }
   
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        rank.resize(n+1);
        vector<int>indegree(n+1);

        vector<vector<int>>result;

        for(int i=0;i<=n;i++){
            parent[i]=i;
            rank[i]=0;
            indegree[i]=0;
        }

        

        for(auto edge:edges){
            indegree[edge[1]]++;
        }

        vector<vector<int>>adj;

        for(int i=0;i<n;i++){
            vector<int>temp;
            int u=edges[i][0];
            int v=edges[i][1];

            temp.push_back(indegree[v]);
            temp.push_back(u);
            temp.push_back(v);
            temp.push_back(i);

            adj.push_back(temp);
        }

        sort(adj.begin(),adj.end(),cmp);



        for(auto edge : adj){
            int u=edge[1];
            int v=edge[2];

            u=findParent(u);
            v=findParent(v);

            if(u==v){
                result.push_back({edge[1],edge[2]});
                continue;
            }

            else{
                makeUnion(u,v);
            }
        }
        return result[result.size()-1];
    }
};