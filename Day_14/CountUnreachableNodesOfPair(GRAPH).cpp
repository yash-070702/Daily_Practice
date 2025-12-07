#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>rank;
    vector<int>parent;
    vector<int>child;
    int n;
    
    void init(){
     for(int i=0;i<n;i++){
        rank[i]=0;
        parent[i]=i;
        child[i]=1;

     }
    }

    int findParent(int node){
        if(node==parent[node])
        return node;

        return parent[node]=findParent(parent[node]);
    }

    void makeSet(int u , int v){
        u=findParent(u);
        v=findParent(v);

        if(u==v){
        return ;
        }

        if(rank[v]>rank[u]){
           
            parent[u]=v;
            child[v]+=child[u];
        }
        else if(rank[u]>rank[v]){
            
            parent[v]=u;
            child[u]+=child[v];
        }
        else{
            parent[v] = u;
            child[u] += child[v];
            rank[u]++;
        }
    }


    long long countPairs(int a, vector<vector<int>>& edges) {
    n=a;
    rank.resize(n);
    parent.resize(n);
    child.resize(n);

    init();

    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        u=findParent(u);
        v=findParent(v);

        if(u==v)
        continue;

        makeSet(u,v);
    }

    long long total=0;
    long long rem=n;

    for(int i=0;i<n;i++){
        if(i==parent[i]){
            long long siz=child[i];
            rem-=siz;
            total+=rem*siz;
        }
    }
    return total;
    }
};