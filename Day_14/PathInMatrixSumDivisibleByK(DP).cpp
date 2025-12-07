#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long MOD=1e9+7;
    vector<vector<vector<int>>>dp;
    int n,m;

    int solve(int i , int j , int rem , vector<vector<int>>&grid,int k){
        if(i>=m || j>=n)
        return 0;

        rem=(rem+grid[i][j])%k;

        if(i==m-1 && j==n-1)
        return (rem==0);

        if(dp[i][j][rem]!=-1)
        return dp[i][j][rem];

        long long right=solve(i,j+1,rem,grid,k);
        long long left=solve(i+1,j,rem,grid,k);

        return (right+left)%MOD;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
    m=grid.size();
    n=grid[0].size();
    dp.assign(m+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));

    return solve(0,0,0,grid,k);
    }
};