#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<int>parent;
    vector<int>rank;
    
    void init(){
        for(int i=0;i<26;i++){
            rank[i]=0;
            parent[i]=i;
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

        if(u==v)
        return ;

        if(rank[u]>rank[v]){

            if(v>u)
            parent[v]=u;

            else{
                int temp=rank[v];
                rank[v]=rank[u];
                rank[u]=temp;
                parent[u]=v;
            }


        }

        else if(rank[v]>rank[u]){

            if(u>v)
            parent[u]=v;

            else{
              int temp=rank[v];
                rank[v]=rank[u];
                rank[u]=temp;
                parent[v]=u;  
            }
        }

        else{
            if(u>v){
                parent[u]=v;
                rank[v]++;
            }
            else{
                parent[v]=u;
                rank[u]++;
            }
        }
    }


    string smallestEquivalentString(string s1, string s2, string baseStr) {
    parent.assign(26,0);
    rank.assign(26,0); 

    init();

    int size=s1.size();

    for(int i=0;i<size;i++){
        int u=s1[i]-'a';
        int v=s2[i]-'a';

        u=findParent(u);
        v=findParent(v);

        if(u==v)
        continue;

        makeSet(u,v);
    }

    string result="";

    for(int i=0;i<baseStr.size();i++){
       int ch= findParent(baseStr[i]-'a');
        result+=(ch+'a');
    }
    return result;
    }
};