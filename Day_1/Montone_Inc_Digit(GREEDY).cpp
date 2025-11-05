#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        bool isAnswer=false;
        string str=to_string(n);
        int size=str.size();

        int index=size-2;

        while(index>=0){
            if(str[index]<=str[index+1]){
                index--;
            continue;
            }

            else{
                int curr=str[index]-'0';
                curr--;
                str[index]=curr+'0';
                fill(str.begin() + index + 1, str.end(), '9');
                index--;
            }
            
        }
return stoi(str);
    }
};