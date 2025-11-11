#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n=arr.size();
        vector<int>nums(n+1,0);
        nums[0]=1;
        
        for(int i=0;i<n;i++){
            nums[arr[i]]++;
        }
        int repeat=-1;;
        int miss=-1;
        for(int i=1;i<=n;i++){
            if(nums[i]==0)
            miss=i;
            
            if(nums[i]==2)
            repeat=i;
        }
        
        return {repeat,miss};
    }
};

