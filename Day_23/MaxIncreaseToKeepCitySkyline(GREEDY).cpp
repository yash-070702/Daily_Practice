#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>rowMax(n);
        vector<int>colMax(n);
        int sum=0;


        for(int i=0;i<n;i++){
            int maxi=INT_MIN;
            for(int j=0;j<n;j++){
                maxi=max(maxi,grid[i][j]);
            }
            rowMax[i]=maxi;
        }

        for(int i=0;i<n;i++){
            int maxi=INT_MIN;
            for(int j=0;j<n;j++){
                maxi=max(maxi,grid[j][i]);
            }
            colMax[i]=maxi;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int rowMaxi=rowMax[i];
                int colMaxi=colMax[j];

                int maxi=max(rowMaxi,colMaxi);
                int mini=min(rowMaxi,colMaxi);

                if(maxi==grid[i][j])
                continue;

                sum+=(mini-grid[i][j]);
                grid[i][j]=mini;
               
            }
        }
      return sum;
    }
};