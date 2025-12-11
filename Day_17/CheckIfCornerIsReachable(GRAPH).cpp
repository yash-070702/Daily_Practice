#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;
    vector<vector<int>> mat;

    bool isSafe(int x, int y){
        return x>=0 && y>=0 && x<=n && y<=m;
    }

    void fillCircle(int cx, int cy, int r){
        long long R = 1LL * r * r;

        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                long long dx = i - cx;
                long long dy = j - cy;
                if(dx*dx + dy*dy <= R){
                    mat[i][j] = 1; 
                }
            }
        }
    }

    bool bfs(){
        queue<pair<int,int>> q;

        if(mat[0][0] == 1) return false;

        q.push({0,0});
        mat[0][0] = 1; 

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()){
            auto curr = q.front(); q.pop();
            int x = curr.first;
            int y = curr.second;

            if(x == n && y == m) return true;

            for(auto &d : dirs){
                int nx = x + d[0];
                int ny = y + d[1];

                if(isSafe(nx, ny) && mat[nx][ny] == 0){
                    mat[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
        }

        return false;
    }

    bool canReachCorner(int xCorner, int yCorner, vector<vector<int>>& circles) {
        n = xCorner;
        m = yCorner;

        mat.assign(n+1, vector<int>(m+1, 0));

        for(auto &cir : circles){
            fillCircle(cir[0], cir[1], cir[2]);
        }

        return bfs();
    }
};
