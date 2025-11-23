#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    pair<int, int> maxSum(vector<int> &arr, int k) {
        
        sort(arr.begin(),arr.end());
       
        int sum=INT_MAX;
        pair<int,int>result={-1,-1};
        
        int n=arr.size();
        int i=0;
        int j=n-1;
        
        while(i<j){
        if(arr[i]+arr[j]>=k){
            j--;
        }
        else{
            int curr=arr[i]+arr[j];
            int diff=abs(curr-k);
            
            if(sum>diff){
                sum=diff;
                result={arr[i],arr[j]};
                i++;
            }
        }
        }
        return result;
    }
};
