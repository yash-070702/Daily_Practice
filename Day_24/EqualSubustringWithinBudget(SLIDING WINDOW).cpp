#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans=0;
        int i=0;
        int n=s.size();
        int cost=0;
        
        for(int j=0;j<n;j++){
        cost+=abs(s[j]-t[j]);

        while(i<=j && cost>maxCost){
            cost-=abs(s[i]-t[i]);
            i++;
        }
        ans=max(ans,(j-i+1));
        }
        return ans;
    }
};