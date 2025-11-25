#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
    vector<int>res;
    vector<int>freqS(26,0);
    vector<int>freqP(26,0);
    int n=s.size();
    int m=p.size();

    if(m>n)
    return {};

    for(char ch : p){
        freqP[ch-'a']++;
    }

    for(int i=0;i<m;i++){
        freqS[s[i]-'a']++;
    }

    if(freqS==freqP){
        res.emplace_back(0);
    }

    for(int i=m;i<n;i++){
        freqS[s[i]-'a']++;
        freqS[s[i-m]-'a']--;

        if(freqP==freqS)
        res.emplace_back(i-m+1);
    }
    return res;
    }
};