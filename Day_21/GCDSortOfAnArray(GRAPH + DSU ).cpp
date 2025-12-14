#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<int> rank, parent;

    int findParent(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }

    void makeSet(int u, int v) {
        u = findParent(u);
        v = findParent(v);
        if (u == v) return;

        if (rank[u] < rank[v]) parent[u] = v;
        else if (rank[u] > rank[v]) parent[v] = u;
        else {
            parent[v] = u;
            rank[u]++;
        }
    }

    bool gcdSort(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());

        
        parent.resize(maxVal + 1);
        rank.resize(maxVal + 1, 0);
        for (int i = 1; i <= maxVal; i++) parent[i] = i;

        
        vector<int> spf(maxVal + 1);
        for (int i = 1; i <= maxVal; i++) spf[i] = i;

        for (int i = 2; i * i <= maxVal; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= maxVal; j += i)
                    if (spf[j] == j) spf[j] = i;
            }
        }

       
        for (int x : nums) {
            int val = x;
            while (val > 1) {
                int p = spf[val];
                makeSet(x, p);
                while (val % p == 0) val /= p;
            }
        }

     
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (findParent(nums[i]) != findParent(sortedNums[i]))
                return false;
        }
        return true;
    }
};
