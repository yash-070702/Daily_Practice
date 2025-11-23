#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
       map<int,int>mp;

       for(int it : arr)
        mp[it]++;
           
       for(auto x : mp){
        int num=x.first;
        int freq=x.second;

        if(freq==0)
        continue;

        int target=num<0?num/2:num*2;

        if(num<0 && num%2!=0)
        return false;

        if(mp[target]<freq)
        return false;

        mp[target]-=freq;
       }    
      return 1;
    }
};