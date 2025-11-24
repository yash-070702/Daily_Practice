#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n ;
    vector<int>parent;
    vector<int>rank;
    int compCount;

    static bool cmp(vector<int>&a , vector<int>&b){
        return a[2]>b[2];
    }

    void init(){
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
        compCount=n;
    }

    int findParent(int node)
    {
        if(parent[node]==node)
        return node;

        return parent[node]=findParent(parent[node]);
    }

    void makeSet(int u , int v){
        u=findParent(u);
        v=findParent(v);

        if(u==v)
        return ;

        if(rank[u]>rank[v])
        parent[v]=u;

        else if(rank[v]>rank[u])
        parent[u]=v;

        else{
            parent[u]=v;
            rank[v]++;
        }

        compCount--;
    }

    int minTime(int a, vector<vector<int>>& edges, int k) {
    n=a;
    rank.resize(n);
    parent.resize(n);
    compCount=0;

    int ans=0;

    init();

    sort(edges.begin(),edges.end(),cmp);

    for(auto edge : edges){
        if(compCount<k)
        break;

        int u=edge[0];
        int v=edge[1];

        int time=edge[2];

        u=findParent(u);
        v=findParent(v);

        if(u==v)
        continue;

        makeSet(u,v);
        
        if(compCount<k){
            ans=time;
            break;
        }
    }

    if(compCount>=k)
    return 0;


   return ans;
    }
};