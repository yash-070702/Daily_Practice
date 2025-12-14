#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        double avg=0.0;
        int count=0;
        int n=arr.size();
        
        double sum=0.0;
        for(int i=0;i<k;i++){
        sum+=(double)arr[i];
        }
        avg=sum/k;
        if(avg>=threshold)
        count++;
        int i=0;

        for(int j=k;j<n;j++){
            avg*=k;
            avg-=(double)arr[i];
            avg+=(double)arr[j];
            avg/=k;

            if(avg>=threshold)
            count++;

            i++;

        }
        return count;
    }
};