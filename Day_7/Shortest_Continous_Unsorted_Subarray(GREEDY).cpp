#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left=-1;
        int right=-1;
        int n=nums.size();
        int maxSeen=INT_MIN;
        int minSeen=INT_MAX;

        for(int i=0;i<n;i++){
            maxSeen=max(maxSeen,nums[i]);
            if(maxSeen>nums[i])
            right=i;
        }

        for(int i=n-1;i>=0;i--){
            minSeen=min(minSeen,nums[i]);
            if(minSeen<nums[i])
            left=i;
        }

        if(left==-1)
        return 0;

        return right-left+1;
    }
};