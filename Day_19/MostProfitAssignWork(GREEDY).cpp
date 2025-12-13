#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {

    priority_queue<pair<int,int>>pq;
    int n=difficulty.size();

    sort(worker.begin(),worker.end());
    int ans=0;

    for(int i=0;i<n;i++){
        pq.push({profit[i],difficulty[i]});
    }
    
    int size=worker.size();

    for(int i=size-1;i>=0;i--){
        
        if(pq.empty())
        break;

        while(!pq.empty() && pq.top().second>worker[i])
        pq.pop();

        if(pq.empty())
        break;
        ans+=pq.top().first;

    }
    return ans;
    }
};

