#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        sort(arr.begin(), arr.end());
    int n = arr.size();

    int bestDiff = INT_MAX;
    int bestSum = INT_MIN;

    for(int i = 0; i < n; i++) {

        int l = i + 1, r = n - 1;

        while(l < r) {

            int sum = arr[i] + arr[l] + arr[r];
            int diff = abs(sum - target);

            
            if(diff < bestDiff || (diff == bestDiff && sum > bestSum)) {
                bestDiff = diff;
                bestSum = sum;
            }

          
            if(sum < target) l++;
            else r--;
        }
    }
    return bestSum; 
    }
};
