#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
      unordered_set<int>st;
      sort(nums.begin(),nums.end());
      int n=nums.size();
    
      int count=0;

      for(int i=1;i<n;i++){
      if(nums[i]<=nums[i-1]){
        int needed=nums[i-1]+1;
        count+=needed-nums[i];
        nums[i]=needed;
      }
      }  
      return count;
    }
};