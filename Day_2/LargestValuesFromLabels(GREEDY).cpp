#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>st;

        int n=values.size();

        for(int i=0;i<n;i++){
        pq.push({values[i],labels[i]});
        }

        int sum=0;

        while(numWanted && !pq.empty()){
        auto top=pq.top();
        pq.pop();
        int num=top.first;
        int limit=top.second;

        if(st.find(limit)!=st.end() && st[limit]>=useLimit)
        continue;

        else{
            sum+=num;
            st[limit]++;
            numWanted--;
        }
        }
    return sum;
    }
};