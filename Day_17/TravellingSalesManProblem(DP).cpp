#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
int n;
vector<vector<int>> dp;

int solve(int city, int mask , vector<vector<int>> &dist) {
    if (mask == (1 << n) - 1) {
        return dist[city][0]; 
    }

    if (dp[city][mask] != -1) {
        return dp[city][mask];
    }

    int ans = INT_MAX;

    for (int next = 0; next < n; ++next) {
        if (!(mask & (1 << next))) { 
            int newMask = mask | (1 << next);
            int cost = dist[city][next] + solve(next, newMask,dist);
            ans = min(ans, cost);
        }
    }

    return dp[city][mask] = ans;
}
     
    int tsp(vector<vector<int>>& cost) {
        n=cost.size();
        dp.assign(n, vector<int>(1 << n, -1));

        return solve(0, 1,cost); 
    }
};