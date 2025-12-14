#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int MOD=1e9+7;
   
    int numberOfWays(string corridor) {
        int n=corridor.length();
        vector<int>seats;

        for(int i=0;i<n;i++){
          if(corridor[i]=='S')
          seats.push_back(i);
        }

        if(seats.size()%2!=0 || seats.size()==0)
        return 0;

        long long result=1;

        int end_length=seats[1];

        for(int i=2;i<seats.size();i+=2){
            int length=seats[i]-end_length;
            result=(result*length)%MOD;
            end_length=seats[i+1];
        }

        return result;
    }
};