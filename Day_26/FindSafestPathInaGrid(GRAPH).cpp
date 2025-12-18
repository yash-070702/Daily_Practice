#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;

    vector<vector<int>>directions={{1,0},{0,1},{0,-1},{-1,0}};

    bool isSafe(int x , int y){
        return x>=0 && y>=0 && x<n && y<n;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
    n=grid.size();
    vector<vector<int>>dist(n,vector<int>(n,-1));
    queue<pair<int,int>>q;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                dist[i][j] = 0; 
                q.push({i,j});
            }
        }
    }

    while(!q.empty()){
        auto curr=q.front();
        int x=curr.first;
        int y=curr.second;
        q.pop();

        for(auto dir : directions){
            int nx=x+dir[0];
            int ny=y+dir[1];

            if(isSafe(nx,ny) && dist[nx][ny]==-1)
            {
                dist[nx][ny]=dist[x][y]+1;
                q.push({nx,ny});
            }
        }
    }

    priority_queue<pair<int,pair<int,int>>>pq;
    vector<vector<bool>>visited(n,vector<bool>(n,false));

    pq.push({dist[0][0], {0, 0}});

    visited[0][0]=true;

    while(!pq.empty()){
        auto curr=pq.top();
        int wt=curr.first;
        int x=curr.second.first;
        int y=curr.second.second;
        pq.pop();

        if(x==n-1 && y==n-1)
        return wt;

        for(auto dir : directions){
            int nx=x+dir[0];
            int ny=y+dir[1];

            if(isSafe(nx,ny) && !visited[nx][ny]){
                visited[nx][ny]=true;
                int newWt = min(wt, dist[nx][ny]);
                pq.push({newWt, {nx, ny}});
            }
        }
    }
return 0;
    }
};