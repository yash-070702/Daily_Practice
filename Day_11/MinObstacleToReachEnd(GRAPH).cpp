#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int m , n;
    vector<vector<int>>dirs={{0,1},{0,-1},{1,0},{-1,0}};
     
    bool isSafe(int x , int y){
        return x>=0 && y>=0 && x<m && y<n;
    } 
    
    int minimumObstacles(vector<vector<int>>& grid) {
    m=grid.size();
    n=grid[0].size();
    deque<pair<int,int>>dq;

    vector<vector<int>>dist(m,vector<int>(n,INT_MAX));

    dist[0][0]=0;
    dq.push_front({0,0});

     while(!dq.empty()){
        auto curr=dq.front();
        dq.pop_front();

        int x=curr.first;
        int y=curr.second;
        int wt=dist[x][y];

        for(int i=0;i<4;i++){
            int nx=x+dirs[i][0];
            int ny=y+dirs[i][1];

            if(isSafe(nx,ny)){
                
                int w=grid[nx][ny];

                if(wt+w<dist[nx][ny]){
                    dist[nx][ny]=wt+w;

                    if(w==0){
                        dq.push_front({nx,ny});
                    }
                    else
                    dq.push_back({nx,ny});
                }
            }
        }
    }
    return dist[m-1][n-1];
    }
};