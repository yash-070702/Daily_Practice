#include<bits/stdc++.h>
using namespace std;

    class Solution {
    public: 
    int m , n ;
    int count=0;
    bool isSub;
    vector<vector<int>>directions={{1,0},{0,1},{-1,0},{0,-1}};

    bool isSafe(int x, int y){
        return (x>=0 && y>=0 && x<m && y<n);
    }
        
        void solve(int i , int j ,vector<vector<int>>&grid1, vector<vector<int>>&grid2){
        
        if(grid1[i][j]==0)
        isSub=false;

        for(auto dir :directions){
            int nx=dir[0]+i;
            int ny=dir[1]+j;

            if(isSafe(nx,ny)&&grid2[nx][ny]==1){
                grid2[nx][ny]=0;
                solve(nx,ny,grid1,grid2);
                }
            }
        }

        int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

            m=grid2.size();
            n=grid2[0].size();

            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid2[i][j]==1){
                        grid2[i][j]=0;
                        isSub=true;
                            solve(i,j,grid1,grid2);
                            if(isSub)
                            count++;
                        }
                    }
                }

            return count;
        }
    };