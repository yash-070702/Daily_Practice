#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int n ;

    void init(){
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }

    int findParent(int node){
        if(parent[node]==node)
        return node;

        else return parent[node]=findParent(parent[node]);
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

    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        n=nums.size();
        parent.resize(n);
        rank.resize(n);

        init();

        vector<pair<int,int>>arr;

        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }

        sort(arr.begin(),arr.end());

        for(int i=1;i<arr.size();i++){
            if(arr[i].first-arr[i-1].first<=limit){
                int u=arr[i].second;
                int v=arr[i-1].second;

                if(u==v)
                continue;

                makeSet(u,v);
            }
        }
        unordered_map<int,vector<int>>group;

        for(int i=0;i<n;i++){
            int p=findParent(i);
            group[p].push_back(i);
        }

        vector<int>result(n);

        for(auto gr:group){
            vector<int>indices=gr.second;
            vector<int>values;

            for(int id : indices){
                values.push_back(nums[id]);
            }

            sort(values.begin(),values.end());
            sort(indices.begin(),indices.end());

            for(int i=0;i<indices.size();i++){
                result[indices[i]]=values[i];
            }
        }
        return result;
    }
};