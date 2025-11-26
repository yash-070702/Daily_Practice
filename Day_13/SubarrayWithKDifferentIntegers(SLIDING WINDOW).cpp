#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int i = 0, count = 0;
        unordered_map<int,int> mp;

        for (int j = 0; j < nums.size(); j++) {
            mp[nums[j]]++;

            while (mp.size() > k) {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) 
                    mp.erase(nums[i]);
                i++;
            }

            count += (j - i + 1);
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};

