#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<vector<vector<int>>>memo;
    int n;

    long long solve(int i , int chance , int k , vector<int>&prices){
        if(i==n){
            if(chance==0)
            return 0;

            return INT_MIN;
        }
         
        if(memo[i][chance][k]!=-1)
        return memo[i][chance][k];

        long long dontTake=solve(i+1,chance , k , prices);

        long long take=INT_MIN;

        if(k>0){
            if(chance==1){
                take=prices[i]+solve(i+1,0,k-1,prices);
            }
            else if(chance==2){
                take=-prices[i]+solve(i+1,0,k-1,prices);
            }
            else
            take=max(-prices[i]+solve(i+1,1,k,prices),prices[i]+solve(i+1,2,k,prices));
        }
        return memo[i][chance][k]=max(take,dontTake);
    }

    long long maximumProfit(vector<int>& prices, int k) {
        n=prices.size();
        memo.assign(n+1,vector<vector<int>>(3,vector<int>(k+1,-1)));
        return solve(0,0,k,prices);
    }
};