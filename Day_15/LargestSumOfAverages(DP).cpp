#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 
    
    int n;
    vector<vector<double>>dp;
    
    double solve(int start, vector<int>&nums , int k  ){
        if(start>=n)
        return 0.0;
        
        if (k == 1) {  
            double sum = 0;
            for (int i = start; i < n; i++) sum += nums[i];
            return sum / (n - start);
        }

        if(dp[start][k]!=-1)
        return dp[start][k];

        double ans=0.0;
        double currSum=0.0;

    for(int i=start;i<n;i++){
        double future=solve(i+1,nums,k-1);
        currSum+=nums[i];
        double currAvg=currSum/(i-start+1);
        ans=max(ans,currAvg+future);
    }
    return dp[start][k]=ans;
    }
    
    double largestSumOfAverages(vector<int>& nums, int k) {
       n=nums.size();
       dp.assign(n + 1, vector<double>(k + 1, -1));
       return solve(0,nums,k);
    }
};