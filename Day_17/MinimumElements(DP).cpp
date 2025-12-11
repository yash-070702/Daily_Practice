#include<bits/stdc++.h>
using namespace std;
 
int n;
int solve(int target,vector<int>&num,vector<int>&dp)
{
    if(target==0)
    return 0;

    if(target<0)
    return INT_MAX;
    
    if(dp[target]!=-1)
    return dp[target];


    int ans=INT_MAX;

    for(int i=0;i<n;i++){
        int currAns=solve(target-num[i],num,dp);

        if(currAns!=INT_MAX)
        currAns++;

        ans=min(ans,currAns);
    }
    return dp[target]=ans;
}

int minimumElements(vector<int> &num, int x)
{
n=num.size();
vector<int>dp(x+1,-1);
int ans=solve(x,num,dp);

if(ans==INT_MAX)
return -1;

return ans;
}