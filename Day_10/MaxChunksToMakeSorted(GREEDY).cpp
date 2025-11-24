#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
       int n=arr.size();
       
       for(int i=1;i<n;i++){
        arr[i]+=arr[i-1];
       }

       int count=0;
       int prefixSum=0;

       for(int i=0;i<n;i++){
        prefixSum+=i;
        if(prefixSum==arr[i])
        count++;
       }
       return count;
    }
};

