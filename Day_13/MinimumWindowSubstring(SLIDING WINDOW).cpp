#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string smallestWindow(string &s, string &p) {
        int n=s.size();
        int m=p.size();
        
        if(m>n)
        return "";
        
        int minLen=INT_MAX;
        unordered_map<char,int>mp;
        
        int requiredCount=m;
        
        for(char ch : p){
            mp[ch]++;
        }
        
        int j=0,i=0,start_i=0;
        
        while(j<n){
            char ch=s[j];
            
            if(mp[ch]>0){
                requiredCount--;
            }
            mp[ch]--;
            
            while(!requiredCount){
                int currSize=j-i+1;
                if(minLen>currSize){
                    minLen=currSize;
                    start_i=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    requiredCount++;
                }
                i++;
            }
            j++;
        }
        return minLen==INT_MAX ? "" : s.substr(start_i,minLen);
    }
};