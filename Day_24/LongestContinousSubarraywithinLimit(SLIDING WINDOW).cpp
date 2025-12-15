#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxdq, mindq;
        int i = 0, ans = 0;

        for (int j = 0; j < nums.size(); j++) {
         
            while (!maxdq.empty() && nums[j] > maxdq.back())
                maxdq.pop_back();
            maxdq.push_back(nums[j]);

            
            while (!mindq.empty() && nums[j] < mindq.back())
                mindq.pop_back();
            mindq.push_back(nums[j]);

        
            while (maxdq.front() - mindq.front() > limit) {
                if (nums[i] == maxdq.front()) maxdq.pop_front();
                if (nums[i] == mindq.front()) mindq.pop_front();
                i++;
            }

            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
