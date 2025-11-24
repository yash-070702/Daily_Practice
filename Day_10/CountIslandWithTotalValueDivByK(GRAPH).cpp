#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
    int n , m;

    bool isSafe(int x , int y){
        return x>=0 && y>=0 && x<n && y<m;
    }

    void dfs(int i , int j , long long &sum,vector<vector<int>>&grid){
    
    sum+=grid[i][j];
    grid[i][j]=0;

    for(auto d : dir){
        int nx=i+d[0];
        int ny=j+d[1];

        if(isSafe(nx,ny) && grid[nx][ny]!=0){
            dfs(nx,ny,sum,grid);
        }
    } 
    }


    int countIslands(vector<vector<int>>& grid, int k) {
    n=grid.size();
    m=grid[0].size();

    int count=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            long long sum=0;
            if(grid[i][j]!=0){
                dfs(i,j,sum,grid);
                if(sum%k==0)
                count++;
            }
        }
    }
    return count;
    }
};