#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string p, string s) {

    vector<int>freqS(26,0);
    vector<int>freqP(26,0);
    int n=s.size();
    int m=p.size();

    if(m>n)
    return false;

    for(char ch : p){
        freqP[ch-'a']++;
    }

    for(int i=0;i<m;i++){
        freqS[s[i]-'a']++;
    }

    if(freqS==freqP){
       return true;
    }

    for(int i=m;i<n;i++){
        freqS[s[i]-'a']++;
        freqS[s[i-m]-'a']--;

        if(freqP==freqS)
        return true;
    }
    return false;
    }
};