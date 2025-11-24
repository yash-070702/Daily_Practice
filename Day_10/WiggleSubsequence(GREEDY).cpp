#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n<2)
        return n;

        int diff=nums[1]-nums[0];
        int count=0;

        count=(diff!=0)?2:1;

        for(int i=2;i<n;i++){
            int curr=nums[i]-nums[i-1];

            if((curr>0 && diff<=0)||(curr<0 && diff>=0)){
                count++;
                diff=curr;
            }
        }
        return count;
    }
};