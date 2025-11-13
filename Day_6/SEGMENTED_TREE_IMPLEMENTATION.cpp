#include<bits/stdc++.h>
using namespace std;

void build(int ind,int low , int high , vector<int>&segtree,vector<int>&arr){
    if(low==high){
        segtree[ind]=arr[low];
        return ;
    }

    int mid = (low+high)/2;
    build(2*ind+1,low,mid,segtree,arr);
    build(2*ind+2,mid+1,high,segtree,arr);
    segtree[ind]=segtree[2*ind+1]+segtree[2*ind+2];
}
int query(int ind , int low , int high , int start, int end ,vector<int>&segtree){
    if(start>high || end<low){
        return 0;
    }

    if(start<=low && high>=end){
        return segtree[ind];
    }

    int mid = (low+high)/2;
    int left = query(2*ind+1,low,mid,start,end,segtree);
    int right = query(2*ind+2,mid+1,high,start,end,segtree);
    return left+right;
}

void update(int ind , int low , int high , int pos , int val,vector<int>&segtree){
    if(low==high){
        segtree[ind]=val;
        return ;
    }

    int mid = (low+high)/2;

    if(pos<=mid){
        update(2*ind+1,low,mid,pos,val,segtree);
    }
    else{
        update(2*ind+2,mid+1,high,pos,val,segtree);
    }
}


int main(){
    vector<int>arr;
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
vector<int>segtree(2*n,0);
build(0,0,n-1,segtree,arr);

cout<<"Segmented Tree: ";

for(int i=0;i<2*n-1;i++){
    cout<<segtree[i]<<" ";
}

return 0;
}