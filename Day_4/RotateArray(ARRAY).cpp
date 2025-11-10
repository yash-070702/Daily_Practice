#include<bits/stdc++.h>
using namespace std;

    class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n=arr.size();
        k=k%n;
        
        vector<int>neww(n);
        
        for(int i=0;i<n;i++){
            neww[(i+k)%n]=arr[i];
        }
        
        for(int i=0;i<n;i++){
            arr[i]=neww[i];
        }
    }
};