#include<bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution {
  public:
    bool pairInSortedRotated(vector<int>& arr, int target) {
        
        int n=arr.size();
        int i;
        for(i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                break;
            }
        }
        
        int l=(i+1)%n;
        int h=(i)%n;
        
        while(l!=h){
            if(arr[l]+arr[h]==target)
            return true;
            
            if(arr[l]+arr[h]<target)
            l=(l+1)%n;
            
            else
            h=(h-1+n)%n;
        }
        return false;
    }
};