#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
        // bool increasingTriplet(vector<int>& nums) {
        // int n = nums.size();
        // if (n < 3) return false;

        // vector<int> leftMin(n), rightMax(n);

        // leftMin[0] = nums[0];
        // for (int i = 1; i < n; i++)
        //     leftMin[i] = min(leftMin[i - 1], nums[i]);

        // rightMax[n - 1] = nums[n - 1];
        // for (int i = n - 2; i >= 0; i--)
        //     rightMax[i] = max(rightMax[i + 1], nums[i]);

        // for (int i = 1; i < n - 1; i++) {
        //     if (leftMin[i - 1] < nums[i] && nums[i] < rightMax[i + 1])
        //         return true;
        // }

        // return false;
        //  }
    //<<<<<<<============OR================>>>>>>>>

     bool increasingTriplet(vector<int>& nums) {
        int min1=INT_MAX;
        int min2=INT_MAX;

        for(int n:nums){
            if(min1>=n)
            min1=n;

            else if(min2>=n){
                min2=n;
            }

            else 
            return true;
        }

        return false;
    }
};

