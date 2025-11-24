#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
       int n=arr.size();

       vector<int>sorted(arr.begin(),arr.end());
       sort(sorted.begin(),sorted.end());
       

       long long prefix1=0;
       long long prefix2=0;
       
       int count=0;
       

       for(int i=0;i<n;i++){
        prefix1+=arr[i];
        prefix2+=sorted[i];

        if(prefix1==prefix2)
        count++;
       }
       
       return count;
    }
};