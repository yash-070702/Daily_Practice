#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double solve(double poured,  int row, int glass, vector<vector<double>>& dp) {
        if(row==0 && glass==0)
        return poured;

        if(row<0 || glass<0 || glass>row)
        return 0.0;

        if(dp[row][glass]!=-1.0)
        return dp[row][glass];

        double leftAns=max(0.0,(solve(poured,row-1,glass-1,dp)-1.0)/2.0);
        double rightAns=max(0.0,(solve(poured,row-1,glass,dp)-1.0)/2.0);

        return dp[row][glass]=leftAns+rightAns;
    }

    double champagneTower(int poured, int row, int glass) {
        vector<vector<double>> dp(row + 1, vector<double>(row + 1, -1.0));
        return min(1.0, solve((double)poured, row, glass, dp));
    }
};
