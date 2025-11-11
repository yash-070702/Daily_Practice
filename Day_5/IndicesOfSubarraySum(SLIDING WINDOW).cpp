#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
    
        int start = 0;
        int end = 0;
        int sum = 0;
        int n = arr.size();
    
        while (end < n) {
            sum += arr[end];
            
            while (sum > target && start <= end) {
                sum -= arr[start++];
            }
            
            if (sum == target) {
                return {start + 1, end + 1};
            }
            
            end++;
        }
    
        return {-1};
    }
};
