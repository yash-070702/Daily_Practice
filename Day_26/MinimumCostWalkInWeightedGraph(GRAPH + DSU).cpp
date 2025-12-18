#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>result;
    vector<int>parent;
    vector<int>rank;
    vector<int>AND;
    int n;
    int qn;

    void init(){
    for(int i=0;i<n;i++){
        parent[i]=i;
        rank[i]=0;
        AND[i]=-1;
    }
    }

    int findParent(int node){
        if(node==parent[node])
        return node;
         
        return parent[node]=findParent(parent[node]);

    }

    void makeSet(int u , int v , int wt){
        u=findParent(u);
        v=findParent(v);

        if(u==v){
         AND[u]&=wt;
         return;
        }

        if(rank[v]>rank[u])
        {
            parent[u]=v;
            AND[v]&=AND[u];
            AND[v]&=wt;
        }

        else if(rank[u]>rank[v]){
            parent[v]=u;
            AND[u]&=AND[v];
            AND[u]&=wt;
        }

        else{
            parent[u]=v;
            AND[v]&=AND[u];
            AND[v]&=wt;
            rank[v]++;
        }


    }

    vector<int> minimumCost(int n1, vector<vector<int>>& edges, vector<vector<int>>& query) {
        n=n1;
        qn=query.size();
        result.resize(qn);
        parent.resize(n);
        rank.resize(n);
        AND.resize(n);

        init();

        for(auto edge : edges){
            makeSet(edge[0],edge[1],edge[2]);
        }

        for(int i=0;i<qn;i++){
            int u=query[i][0];
            int v=query[i][1];

            u=findParent(u);
            v=findParent(v);

            if(u==v)
            result[i]=AND[u];

            else 
            result[i]=-1;
        }
     return result;
    }
};  