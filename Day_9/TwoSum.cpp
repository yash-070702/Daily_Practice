#include<bits/stdc++.h>
using namespace std;

string read(int n, vector<int> book, int target)
{
    unordered_map<int,int>mp;

    for(int i=0;i<n;i++){
        mp[book[i]]=i;
    }

    for(int i=0;i<n;i++){
        int curr=target-book[i];

        if(mp.find(curr)!=mp.end() && i>mp[curr])
        return "YES";
    }

    return "NO";
}
