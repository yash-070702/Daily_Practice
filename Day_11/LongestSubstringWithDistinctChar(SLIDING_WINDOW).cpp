#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int i=0;
        int n=s.size();
        int j=0;
        
        unordered_set<char>st;
        int len=0;
        
        while(j<n){
        if(st.count(s[j]) && i<j){
            st.erase(s[i]);
            i++;
            len=max(len,(j-i+1));
        }
        else{
            st.insert(s[j]);
            len=max(len,(j-i+1));
            j++;
        }
        }
        return len;
    }
};
