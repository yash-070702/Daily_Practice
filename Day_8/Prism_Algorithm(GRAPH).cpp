#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    typedef pair<int,int> P;   // {weight, node}

    int spanningTree(int V, vector<vector<int>>& edges) {

        // Build adjacency list
        vector<vector<pair<int,int>>> adj(V);

        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Prim's Algorithm
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});     // {weight, node}

        vector<bool> inMST(V, false);

        int sum = 0;

        while(!pq.empty()) {

            
            int wt=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            if(inMST[node]) continue;

            inMST[node] = true;
            sum += wt;

            for(auto &nbr : adj[node]) {
                int v = nbr.first;
                int w = nbr.second;

                if(!inMST[v]) {
                    pq.push({w, v});
                }
            }
        }

        return sum;
    }
};
