#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
     unordered_map<int,int>mp;
     unordered_map<int,bool>vis;

    void dfs(int node,int &count){
        count++;
        vis[node]=true;

        if(!vis[mp[node]])
        dfs(mp[node],count);
    } 
      
    int arrayNesting(vector<int>& nums) {
       
        int ans=INT_MIN;
        int n=nums.size();

        for(int i=0;i<n;i++){
            mp[i]=nums[i];
        }

        for(int i=0;i<n;i++){
            int count=0;

            dfs(i,count);
            ans=max(ans,count);

        }
 
        return ans;
    }
};