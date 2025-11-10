#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
       unordered_set<int>s1;
       
       for(int ar:a){
           s1.insert(ar);
       }
       
       set<int>s2;
       
       for(int arr : b){
           if(s1.count(arr)){
               s2.insert(arr);
           }
       }
       
       vector<int>result(s2.begin(),s2.end());
       return result;
    }
};