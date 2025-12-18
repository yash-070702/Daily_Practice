#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<vector<int>>>dp;
    int n1,n2,n3;

    int solve(int i , int j , int k , string &s1 , string &s2 , string &s3){
        if(k==n3){
            if(i==n1 && j==n2)
            return true;

            return false;
        }

        if(dp[i][j][k]!=-1)
        return dp[i][j][k];

        bool ans=false;

        if(s1[i]==s3[k])
        ans=solve(i+1,j,k+1,s1,s2,s3);

        if(!ans && s2[j]==s3[k])
        ans=solve(i,j+1,k+1,s1,s2,s3);

       return dp[i][j][k]=ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        n1=s1.size();
        n2=s2.size();
        n3=s3.size();
        
        dp.assign(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,-1)));
        return solve(0,0,0,s1,s2,s3);
    }
};