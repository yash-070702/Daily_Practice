#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   int n;
    int maximumSwap(int num) {
       string str=to_string(num); 
       n=str.size();
       int firstIndex=-1;
       char curr;

       string temp=str;
       sort(temp.rbegin(),temp.rend());

       for(int i=0;i<n;i++){
        if(str[i]==temp[i])
        continue;

        else{
            curr=temp[i];
            firstIndex=i;
            break;
        }
       }
       if(firstIndex==-1)
       return num;

       int secondIndex=str.rfind(curr);

       swap(str[firstIndex],str[secondIndex]);
       return stoi(str);
    }
};