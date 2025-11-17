#include<bits/stdc++.h>
using namespace std;

class NumArray {
public:
    vector<int>seg;
    int n;

    void buildTree(int ind , int low , int high , vector<int>&nums){
        if(low==high)
        {
            seg[ind]=nums[low];
            return ;
        }

        int mid=(low+high)/2;

        buildTree(2*ind+1,low,mid,nums);
        buildTree(2*ind+2,mid+1,high,nums);

        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
        return ;

    }

    void updateTree(int ind , int low , int high , int i,int val){
        if(low==high){
            seg[i]=val;
            return ;
        }

        int mid=(low+high)/2;

        if(ind<=mid){
            updateTree(ind,low,mid,2*i+1,val);
        }
        else
        updateTree(ind,mid+1,high,2*i+2,val);

        seg[i]=seg[2*i+1]+seg[2*i+2];
        return ;
    }

    int sumTree(int ind , int low , int high , int start , int end){
        if(start>high || low>end)
        return 0;

        if(low>=start && high<=end)
        return seg[ind];

        int mid=(low+high)/2;

        int left=sumTree(2*ind+1,low,mid,start,end);
        int right=sumTree(2*ind+2,mid+1,high,start,end);

        return left+right;
     }

    NumArray(vector<int>& nums) {
        n=nums.size();
        seg.resize(4*n);
        buildTree(0,0,n-1,nums);
    }
    
    void update(int index, int val) { 
    updateTree(index,0,n-1,0,val);
    }
    
    int sumRange(int left, int right) {
        return sumTree(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */