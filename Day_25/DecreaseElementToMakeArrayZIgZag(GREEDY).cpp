#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int solve(vector<int>& nums, int parity) {
        int n = nums.size();
        int moves = 0;

        for (int i = 0; i < n; i++) {
            if (i % 2 == parity) {   
                int left = (i > 0) ? nums[i - 1] : INT_MAX;
                int right = (i + 1 < n) ? nums[i + 1] : INT_MAX;

                int target = min(left, right) - 1;
                if (nums[i] > target) {
                    moves += nums[i] - target;
                }
            }
        }
        return moves;
    }

    int movesToMakeZigzag(vector<int>& nums) {
        int evenValley = solve(nums, 0); 
        int oddValley  = solve(nums, 1); 
        return min(evenValley, oddValley);
    }
};
