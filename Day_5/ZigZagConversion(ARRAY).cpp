#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    void zigZag(vector<int> &arr) {
        
        int i=0;
        int n=arr.size();
        
        while(i<n-1){
            if(i&1){
                if(arr[i]<arr[i+1])
                swap(arr[i],arr[i+1]);
            }
            else{
                if(arr[i]>arr[i+1])
                swap(arr[i],arr[i+1]);
            }
            i++;
        }
    }
};


