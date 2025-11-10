#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
       set<int>st;
       
       for(int ar : a){
           st.insert(ar);
       }
       for(int ar : b){
           st.insert(ar);
       }
       
       vector<int>result(st.begin(),st.end());
       
       return result;
        
    }
};