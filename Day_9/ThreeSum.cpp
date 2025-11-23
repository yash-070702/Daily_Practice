#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> triplets(vector<int> &arr) {
        vector<vector<int>> ans;
        int n = arr.size();

        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && arr[i] == arr[i-1]) continue;

            int l = i + 1, r = n - 1;

            while (l < r) {
                int sum = arr[i] + arr[l] + arr[r];
                if (sum == 0) {
                    ans.push_back({arr[i], arr[l], arr[r]});
                    l++; r--;
                    while (l < r && arr[l] == arr[l-1]) l++;
                    while (l < r && arr[r] == arr[r+1]) r--;
                }
                else if (sum < 0) l++;
                else r--;
            }
        }
        return ans;
    }
};
