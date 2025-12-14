#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<set<int>>row(m);
        vector<set<int>>col(n);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                row[i].insert(j);
                col[j].insert(i);
            }
        }

        queue<pair<int,int>>q;

        q.push({0,0});
        row[0].erase(0);
        col[0].erase(0);

        int steps=1;

        while(!q.empty()){
            int size=q.size();

            while(size--){
                auto top=q.front();
                q.pop();

                int x=top.first;
                int y=top.second;

                if(x==m-1 && y==n-1)
                return steps;

                int reach=grid[x][y];

                for(auto it=row[x].lower_bound(y+1) ; it!=row[x].end() && *it<=reach+y;){
                    int nextCol=*it;
                    q.push({x,nextCol});
                    col[nextCol].erase(x);
                    it=row[x].erase(it);
                }

                for(auto it=col[y].lower_bound(x+1) ; it!=col[y].end() && *it<=reach+x;){
                    int nextRow=*it;
                    q.push({nextRow,y});
                    row[nextRow].erase(y);
                    it=col[y].erase(it);
                }
            }
            steps++;
        }
        return -1;
    }
};