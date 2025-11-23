#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> distinctPairs(vector<int> &arr, int target) {
        
         vector<vector<int>>result;
        
        unordered_map<int,int>mp;
        
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=i;
        }
        
        for(int i=0;i<arr.size();i++){
            int curr=target-arr[i];
            
            if(mp.find(curr)!=mp.end() && mp[curr]>i){
            result.push_back({curr,arr[i]}); 
            }
           
        }
        sort(result.begin(),result.end());
        return result;
    }
};