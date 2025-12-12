#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string>middle;
        unordered_set<string>st;

        for(int i=0;i+10<=s.size();i++){
            string str=s.substr(i,10);

            if(st.count(str))
            middle.insert(str);

            st.insert(str);
        }
      vector<string>result(middle.begin(),middle.end());
      return result;
    }
};