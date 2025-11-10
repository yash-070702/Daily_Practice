#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
      
    int maxSubarraySum(vector<int>& arr) {
        int n = arr.size();
        int sum=0;
        int maxi=arr[0];

        for (int i = 0; i < n; i++) {
            sum+=arr[i];
            maxi=max(maxi,sum);
            
            if(sum<0)
            sum=0;
        }

        return maxi;
    }
};
