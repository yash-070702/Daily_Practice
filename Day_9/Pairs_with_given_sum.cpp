#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int count=0;
        
        unordered_map<int,list<int>>mp;
        
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        
        for(int i=0;i<arr.size();i++){
            int curr=target-arr[i];
            
            if(mp.find(curr)!=mp.end()){
                for(int it : mp[curr]){
                    if(it>i)
                     count++;
                }
            }
           
        }
        return count;
    }
};