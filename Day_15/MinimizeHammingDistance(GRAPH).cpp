#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<int>parent;
    vector<int>rank;

    void init(){
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }

    int findParent(int node)
    {
        if(node==parent[node])
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
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
     n=source.size();
     parent.assign(n,0);
     rank.assign(n,0);   

     init();
      
     for(auto swapped : allowedSwaps){
        int u=swapped[0];
        int v=swapped[1];

        makeSet(u,v);
     }
     unordered_map<int,list<int>>groups;

     for(int i=0;i<n;i++){
        groups[findParent(i)].push_back(i);
     }

     int result=0;

     for(auto group : groups){
        unordered_map<int,int>count;

        for(int idx : group.second){
            count[source[idx]]++;
        }

        for(int idx : group.second){
            if(count[target[idx]]>0){
                count[target[idx]]--;
            }
            else
            result++;
        }
     }
    return result;

    }
};