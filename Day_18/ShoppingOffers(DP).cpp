#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    map<vector<int>, int> memo;
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int> needs) {
     int cost=0;
     int n=price.size();

     if(memo.count(needs))
     return memo[needs];

     for(int i=0;i<n;i++){
        cost+=price[i]*needs[i];
     }

     for(auto offer : special){
        vector<int>nextNeed=needs;
        bool valid=true;

        for(int i=0;i<n;i++){
            nextNeed[i]-=offer[i];
            if(nextNeed[i]<0){
             valid=false;
             break;
            }
        }
        if(valid)
        cost=min(cost,offer[n]+shoppingOffers(price,special,nextNeed));
     }
     return memo[needs]=cost;
    }
};
