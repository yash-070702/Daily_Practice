#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m,n;
    
    bool isSafe(int x , int y){
        return x>=0 && y>=0 && x<m && y<n;
    }

    vector<vector<int>>directions={{1,0},{0,1},{-1,0},{0,-1}};

    int dfs(int x , int y , vector<vector<int>>&grid){
        int count=grid[x][y];
        grid[x][y]=0;

        for(auto dir : directions){
            int nx=x+dir[0];
            int ny=y+dir[1];

            if(isSafe(nx,ny) && grid[nx][ny]!=0)
            count+=dfs(nx,ny,grid);
        }
        return count;
    }

    int findMaxFish(vector<vector<int>>& grid) {
       int count=INT_MIN;

       m=grid.size();
       n=grid[0].size();

       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]!=0)
            {
                count=max(count,dfs(i,j,grid));
            }
        }
       }
   if(count!=INT_MIN)    
   return count;

   return 0;
    }
};