#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    static bool cmp(vector<int>&a , vector<int>&b){
        if(a[0]==b[0])
            return a[1]<b[1];
        return a[0]<b[0];
    }
    
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        
        unordered_map<int, vector<int>> row_map;  
        unordered_map<int, vector<int>> col_map; 

        sort(buildings.begin(), buildings.end(), cmp);

        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            row_map[x].push_back(y);
            col_map[y].push_back(x);
        }

        int covered = 0;

        for (auto &b : buildings) {
            int x = b[0], y = b[1];

           
            auto &ys = row_map[x];
        
            auto it = lower_bound(ys.begin(), ys.end(), y);
            bool has_left = (it != ys.begin());            
            bool has_right = ( (it+1) != ys.end() );     

            if (!has_left || !has_right) 
                continue; 

            
            auto &xs = col_map[y];
            auto it2 = lower_bound(xs.begin(), xs.end(), x);
            bool has_up   = (it2 != xs.begin());
            bool has_down = ( (it2+1) != xs.end() );

            if (has_up && has_down) {
                covered++;
            }
        }

        return covered;
    }
};
