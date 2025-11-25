#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=0,res=0;
        int n=s.size();
        unordered_map<char,int>mp;
        int maxFreq=0;

        while(j<n){
            mp[s[j]]++;
            maxFreq=max(maxFreq,mp[s[j]]);

            while((j-i+1)-maxFreq>k){
                mp[s[i]]--;
                i++;
            }
            res=max(res,(j-i+1));
           j++;
        }
        return res;
    }
};