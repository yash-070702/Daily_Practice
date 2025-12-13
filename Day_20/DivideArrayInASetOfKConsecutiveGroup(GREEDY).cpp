#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
    int n=hand.size();

     if(n%groupSize!=0)
     return false;

     int count=n/groupSize;

    map<int,int>freq;

    for(auto it : hand){
    freq[it]++;
    }

     for(int i=0;i<count;i++){
        auto it = freq.begin();
        int number=it->first;

        freq[number]--;
        if(freq[number]==0)
        freq.erase(number);

        for(int ch=2; ch<=groupSize ; ch++){
            int currNumber=number+1;

            if(freq.count(currNumber)==0)
            return false;
            
            number=currNumber;
            freq[currNumber]--;

            if(freq[currNumber]==0)
            freq.erase(currNumber);

        }
     }
 return true;
    }
};