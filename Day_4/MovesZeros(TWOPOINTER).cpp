#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& arr) {
      int n =arr.size();
      int i=0;
      int j=0;
      
      while(i<n && j<n){
          if(arr[i]!=0){
              i++;
              j++;
          }
          else{
              if(arr[j]!=0){
                  swap(arr[i],arr[j]);
                  i++;
              }
              else{
                  j++;
              }
          }
      }
      return ;
    }
};