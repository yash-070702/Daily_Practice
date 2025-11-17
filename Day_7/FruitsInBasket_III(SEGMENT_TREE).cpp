#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>segment;
    int n; 

    void buildTree(int ind , int low , int high , vector<int>&baskets){
        if(low==high)
        {
            segment[ind]=baskets[low];
            return ;
        }

        int mid=(low+high)/2;

        buildTree(2*ind+1,low,mid,baskets);
        buildTree(2*ind+2,mid+1,high,baskets);

        segment[ind]=max(segment[2*ind+1],segment[2*ind+2]);
        return ;
    }

    bool isPossible(int fruit , int ind , int low , int high){
        if(segment[ind]<fruit)
        return false;

        if(low==high){
         segment[ind]=-1;
         return true;
        }

        int mid=(low+high)/2;
        bool placed=false;

        if(segment[2*ind+1]>=fruit)
        placed=isPossible(fruit , 2*ind+1, low, mid);

        else
        placed=isPossible(fruit,2*ind+2,mid+1,high);

        segment[ind] = max(segment[2*ind+1], segment[2*ind+2]);

        return placed;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    
      n=fruits.size();
      
      segment.assign(4*n,-1);

      int unplaced=0;
      buildTree(0,0,n-1,baskets);

      for(int fruit : fruits){
        if(!isPossible(fruit ,0, 0, n-1))
        unplaced++;
      }
    return unplaced;
    }
};