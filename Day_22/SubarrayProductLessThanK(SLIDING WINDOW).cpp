#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int product=1;
        int i=0;
        int n=nums.size();
        int count=0;

        for(int j=0;j<n;j++){
            product*=nums[j];
            
            while(i<=j && product>=k){
                product/=nums[i];
                i++;
            }
            count+=(j-i+1);
        }
       return count;
    }
};