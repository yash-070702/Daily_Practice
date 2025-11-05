#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> count(n, 0);
        vector<int> res(n, 0);

        dfs1(0, -1, adj, count, res);
        dfs2(0, -1, adj, count, res, n);

        return res;
    }

    void dfs1(int node, int parent, vector<vector<int>>& adj,
              vector<int>& count, vector<int>& res) {
        count[node] = 1;
        for (auto nbr : adj[node]) {
            if (nbr == parent) continue;
            dfs1(nbr, node, adj, count, res);
            count[node] += count[nbr];
            res[node] += res[nbr] + count[nbr];
        }
    }

    void dfs2(int node, int parent, vector<vector<int>>& adj,
              vector<int>& count, vector<int>& res, int n) {
        for (auto nbr : adj[node]) {
            if (nbr == parent) continue;
            res[nbr] = res[node] - count[nbr] + (n - count[nbr]);
            dfs2(nbr, node, adj, count, res, n);
        }
    }
};
