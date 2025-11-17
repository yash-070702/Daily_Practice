#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
       unordered_map<int,int>freq,need;

       for(int num : nums){
        freq[num]++;
       }

       for(int x : nums){
        if(freq[x]==0)
        continue;

        if(need[x]>0){
            need[x]--;
            need[x+1]++;
            freq[x]--;
        }

        else if(freq[x+1]>0 && freq[x+2]>0)
        {
            freq[x]--;
            freq[x+1]--;
            freq[x+2]--;
            need[x+3]++;
        }

        else
        return false;
       }
       return true;
    }
};

