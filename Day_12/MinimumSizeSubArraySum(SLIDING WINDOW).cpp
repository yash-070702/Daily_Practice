#include<bits/stdc++.h>
using namespace std;

    class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int n=nums.size();
            int i=0;
            int j=0;
            int sum=0;
            int length=n+1;

            while(j<n){
                if(sum<target){
                    sum+=nums[j];
                    j++;
                }
            while (sum >= target) {   
            length = min(length, j - i);
            sum -= nums[i]; 
            i++;
        }
            }

        

            return (length == n + 1 ? 0 : length);
        
        }
    };