#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    unordered_map<string,vector<int>>mp;


    vector<int> diffWaysToCompute(string exp) {
        
        if(mp.count(exp))
        return mp[exp];

        vector<int>result;

        for(int i=0;i<exp.length();i++){
        char ch=exp[i];

        if(ch=='*'||ch=='+'||ch=='-'){
            vector<int>left=diffWaysToCompute(exp.substr(0,i));
            vector<int>right=diffWaysToCompute(exp.substr(i+1));

            for(int a :left){
                for(int b:right){
                    if(ch=='*')
                    result.push_back(a*b);

                    else if(ch=='+')
                    result.push_back(a+b);

                    else
                    result.push_back(a-b);
                }
            }
        }
        }
        if(result.size()==0)
        result.push_back(stoi(exp));

        return mp[exp]=result;
    }
};