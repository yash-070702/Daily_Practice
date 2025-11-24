#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compCount=0;
    int n ;
    vector<int>rank;
    vector<int>parent;
    vector<int>cost;

    static bool cmp(vector<int>&a , vector<int>&b){
        return a[2]<b[2];
    }

    void init(){
        for(int i=0;i<n;i++){
            rank[i]=0;
            parent[i]=i;
            cost[i]=0;
        }
        compCount=n;
    }

    int findParent(int node){
        if(node==parent[node])
        return node;

        return parent[node]=findParent(parent[node]);
    }

    void makeSet(int u , int v , int val){
        u=findParent(u);
        v=findParent(v);

        if(u==v)
        return ;


        if(rank[u]>rank[v]){
        parent[v]=u;
        cost[u]=max({cost[u],cost[v],val});
        }

        else if(rank[v]>rank[u]){
        parent[u]=v;
         cost[u]=max({cost[u],cost[v],val});
        }

        else{
            parent[u]=v;
            rank[v]++;
            cost[u]=max({cost[u],cost[v],val});
        }

        compCount--;
    }
    int minCost(int a, vector<vector<int>>& edges, int k) {
       n=a;
       rank.resize(n);
       parent.resize(n);
       cost.resize(n);
       compCount=n;

       init();

       sort(edges.begin(),edges.end(),cmp);


       for(auto edge :edges){
        
        if(compCount==k)
        break;

        int u=edge[0];
        int v=edge[1];
        int wt=edge[2];

        u=findParent(u);
        v=findParent(v);

        if(u==v)
        continue;

        makeSet(u,v,wt);
    
        if(compCount==k)
        break;
       }

return *max_element(cost.begin(),cost.end());
    }
};