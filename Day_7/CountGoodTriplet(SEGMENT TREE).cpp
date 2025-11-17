#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<long long>segment;
    int n; 
    
    int query(int qs, int qe , int i , int l , int h ){
     if(qe<l ||qs>h)
     return 0;

    if(qs <=l && qe>=h)
    return segment[i];
     
    int mid=(l+h)/2;

    int left=query(qs,qe,2*i+1,l,mid);
    int right=query(qs,qe,2*i+2,mid+1,h); 

    return left+right;
    }

    void update(int i , int left , int right , int idx){
        if(left==right)
        {
            segment[i]=1;
            return ;
        }

        int mid=(left+right)/2;

        if(idx<=mid)
        update(2*i+1,left,mid,idx);

        else
        update(2*i+2,mid+1,right,idx);

        segment[i]=segment[2*i+1]+segment[2*i+2];

        return ;
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
    n=nums1.size();
    segment.assign(4*n,0);
    long long result=0;

    unordered_map<int,int>mp;

    for(int i=0;i<n;i++){
        mp[nums2[i]]=i;
    }

    update(0,0,n-1,mp[nums1[0]]);

    for(int i=1;i<n;i++){
        int idx=mp[nums1[i]];

        long long commonElementLeft=query(0,idx-1,0,0,n-1);
        long long unCommonElementLeft=i-commonElementLeft;

        long long rightCommon=n-idx-1-unCommonElementLeft;

        result+=(long long)(commonElementLeft*rightCommon);
        update(0,0,n-1,mp[nums1[i]]);
    }

    return result;   
    }
};