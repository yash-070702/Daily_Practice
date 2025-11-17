#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int n;
    vector<int>segment;
    vector<int>result;

    void buildTree(int i , int low , int high , vector<int>&heights){
        if(low==high)
        {
            segment[i]=low;
            return ;
        }

        int mid=(low+high)/2;
        buildTree(2*i+1,low,mid,heights);
        buildTree(2*i+2,mid+1,high,heights);

        int leftInd=segment[2*i+1];
        int rightInd=segment[2*i+2];

        if(heights[leftInd]>heights[rightInd])
            segment[i]=leftInd;
        else
            segment[i]=rightInd;
    }

    int solve(vector<int>&heights , int i , int low , int high , int l , int r){
        if(r<low || high<l) return -1;
        if(l<=low && high<=r) return segment[i];

        int mid=(low+high)/2;

        int a=solve(heights,2*i+1,low,mid,l,r);
        int b=solve(heights,2*i+2,mid+1,high,l,r);

        if(a==-1) return b;
        if(b==-1) return a;
        if(heights[a]>heights[b]) return a;
        return b;
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
       n=heights.size();
       segment.resize(4*n);
       buildTree(0,0,n-1,heights);

       for(auto q : queries){
            int minInd=min(q[0],q[1]);
            int maxInd=max(q[0],q[1]);

            if(minInd==maxInd)
            {
                result.push_back(minInd);
                continue;
            }

            if(heights[maxInd]>heights[minInd]){
                result.push_back(maxInd);
                continue;
            }

            int result_ind=INT_MAX;
            int low=maxInd+1;
            int high=n-1;

            int need=max(heights[minInd],heights[maxInd]);

            while(low<=high){
                int mid=(low+high)/2;

                int idx=solve(heights,0,0,n-1,low,mid);

                if(idx!=-1 && heights[idx]>need){
                    result_ind=idx;
                    high=mid-1;
                }
                else
                    low=mid+1;
            }

            if(result_ind==INT_MAX)
                result.push_back(-1);
            else
                result.push_back(result_ind);
        } 

       return result;
    }
};
