#include<bits/stdc++.h>
using namespace std;




void buildTree(int ind , int l ,int h , int segmentTree[] , int arr[]){
    if(l==h){
        segmentTree[ind]=arr[l];
        return ;
    }
    
    int mid=(l+h)/2;
    
    buildTree(2*ind+1,l,mid,segmentTree,arr);
    buildTree(2*ind+2,mid+1,h,segmentTree,arr);
    
    segmentTree[ind]=min(segmentTree[2*ind+1],segmentTree[2*ind+2]);
    return ;
}

int *constructST(int arr[], int n) {
    
int *segmentTree=new int[4*n];
buildTree(0,0,n-1,segmentTree,arr);
return segmentTree;

}

 int query(int index , int start, int end , int l , int r , int segmentTree[]){
        if(end<l || r<start)
        return INT_MAX;
        
        if(l>=start && r<=end)
        return segmentTree[index];
    
    int mid=(l+r)/2;
    int left=query(2*index+1,start,end,l,mid,segmentTree);
    int right=query(2*index+2,start,end,mid+1,r,segmentTree);
    
    return min(left,right);
}


int RMQ(int st[], int n, int a, int b) {

return query(0,a,b,0,n-1,st);

}