#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totalSum=accumulate(nums.begin(),nums.end(),0);

        int currSum=0;
        int ans=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            currSum+=nums[i];
            totalSum-=nums[i];

            if(!((totalSum-currSum)&1))
            ans++;
        }
        if(ans==0)
        return ans;

        return ans-1;
    }
};