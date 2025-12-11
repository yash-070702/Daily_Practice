#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int n ;
    bool isSafe(int x , int y){
        return x>=0 && y>=0 && x<3*n && y<3*n;
    }

    vector<vector<int>>dires={{1,0},{0,1},{-1,0},{0,-1}};

    void dfs(int x , int y,vector<vector<int>>&exp){
    exp[x][y]=1;

    for(auto dir : dires){
        int nx=dir[0]+x;
        int ny=dir[1]+y;
        
        if(isSafe(nx,ny) && exp[nx][ny]==0)
          dfs(nx,ny,exp);
    }
    }

    int regionsBySlashes(vector<string>& grid) {
    n =grid.size();
    vector<vector<int>>expand(3*n,vector<int>(3*n,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            if(grid[i][j]=='/'){
                expand[3*i+2][3*j+0]=1;
                expand[3*i+1][3*j+1]=1;
                expand[3*i+0][3*j+2]=1;
            }

             else if(grid[i][j]=='\\'){
                expand[3*i+0][3*j+0]=1;
                expand[3*i+1][3*j+1]=1;
                expand[3*i+2][3*j+2]=1;
             }
        }
    }

    int count=0;

    for(int i=0;i<3*n;i++){
        for(int j=0;j<3*n;j++){
            if(expand[i][j]==0){
                dfs(i,j,expand);
                count++;
            }
        }
    }
    return count;
    }
};