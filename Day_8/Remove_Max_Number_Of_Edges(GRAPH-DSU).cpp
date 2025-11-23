#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int n;
    vector<int> parentA, parentB;
    vector<int> rankA, rankB;

    void init() {
        for(int i = 1; i <= n; i++) {
            parentA[i] = parentB[i] = i;
            rankA[i] = rankB[i] = 0;
        }
    }

    int findParent(vector<int> &parent, int node) {
        if(parent[node] == node)
            return node;
        return parent[node] = findParent(parent, parent[node]);
    }

    bool makeUnion(vector<int> &parent, vector<int> &rank, int u, int v) {
        u = findParent(parent, u);
        v = findParent(parent, v);

        if(u == v) return false;

        if(rank[u] > rank[v]) parent[v] = u;
        else if(rank[v] > rank[u]) parent[u] = v;
        else {
            parent[u] = v;
            rank[v]++;
        }
        return true;
    }

    int maxNumEdgesToRemove(int size, vector<vector<int>>& edges) {
        n = size;
        parentA.resize(n+1);
        parentB.resize(n+1);
        rankA.resize(n+1);
        rankB.resize(n+1);

        init();

        int remove = 0;
        int aliceJoin = 0, bobJoin = 0;

       
        for(auto &e : edges) {
            if(e[0] == 3) {
                bool a = makeUnion(parentA, rankA, e[1], e[2]);
                bool b = makeUnion(parentB, rankB, e[1], e[2]);

                if(!a && !b) remove++;
                else {
                    aliceJoin++;
                    bobJoin++;
                }
            }
        }

        
        for(auto &e : edges) {
            if(e[0] == 1) {
                if(!makeUnion(parentA, rankA, e[1], e[2])) remove++;
                else aliceJoin++;
            }
        }

        
        for(auto &e : edges) {
            if(e[0] == 2) {
                if(!makeUnion(parentB, rankB, e[1], e[2])) remove++;
                else bobJoin++;
            }
        }

       
        if(aliceJoin != n-1 || bobJoin != n-1)
            return -1;

        return remove;
    }
};
