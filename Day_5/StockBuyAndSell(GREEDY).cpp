#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
    
    int n=prices.size();
    int buy=prices[0];
    int ret = 0;
    
    for(int i=1;i<n;i++){
        if(prices[i]>=buy){
          ret=max(ret,prices[i]-buy);  
        }
        else
        buy=prices[i];
    }
    return ret;
    }
};
