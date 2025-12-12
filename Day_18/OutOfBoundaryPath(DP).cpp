#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> dires = {{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<vector<int>>> dp;
    const int MOD = 1e9 + 7;

    int solve(int x, int y, int m, int n, int currMoves, int maxMoves) {
        if (x < 0 || y < 0 || x >= m || y >= n)
            return 1;
        if (currMoves == maxMoves)
            return 0;

        if (dp[x][y][currMoves] != -1)
            return dp[x][y][currMoves];

        long long ans = 0;
        for (auto &dir : dires) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            ans = (ans + solve(nx, ny, m, n, currMoves + 1, maxMoves)) % MOD;
        }

        return dp[x][y][currMoves] = ans;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp.assign(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return solve(startRow, startColumn, m, n, 0, maxMove);
    }
};
