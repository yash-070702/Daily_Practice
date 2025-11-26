#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int i=0;
        int j=0;
        int n=arr.size();
        int len=0;

        while(j<n){
            if(arr[j]==1){
                len=max(len,(j-i+1));
                j++;
            }

            else if(arr[j]==0 && k>0){
                k--;
                arr[j]=2;
                len=max(len,(j-i+1));
                j++;
            }
            else{
                while(i<j && arr[i]!=2){
                    i++;
                }
                arr[i]=0;
                k++;
                i++;
                len=max(len,(j-i+1));
            }
        }
        return len;
    }
};