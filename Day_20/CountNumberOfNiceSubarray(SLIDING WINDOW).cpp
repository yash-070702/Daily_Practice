#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, result = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] & 1) k--;
            while (k < 0) {
                if (nums[i] & 1) k++;
                i++;
            }
            result += j - i + 1;
        }
        return result;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
