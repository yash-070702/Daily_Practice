#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void rearrange(vector<int> &arr) {
        vector<int>pos;
        vector<int>neg;
        int n=arr.size();
       
        
        
        for(int i : arr){
            if(i<0)
            neg.push_back(i);
            
            else
            pos.push_back(i);
        }
        
         int n1=pos.size();
        int n2=neg.size();
        
        int first=0;
        int sec=0;
        int ind=0;
        
        while(ind< n && first <n1 && sec <n2){
            arr[ind++]=pos[first++];
            arr[ind++]=neg[sec++];
        }
        
        if(ind>=n)
        return ;
        
        while(first<n1){
           arr[ind++]=pos[first++]; 
        }
        
        while(sec<n2){
            arr[ind++]=neg[sec++]; 
        }
        

    }
};