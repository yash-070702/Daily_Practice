#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int MOD=1e9+7;
    
    int countPermutations(vector<int>& comp) {
      long long count=1;
      int n=comp.size();
      int first=comp[0];

      for(int i=1;i<n;i++){
        if(comp[i]<=first)
        return 0;
      }

      for(int i=1;i<n;i++){
        count=(count*i)%MOD;
      }

      return count;
    }
};