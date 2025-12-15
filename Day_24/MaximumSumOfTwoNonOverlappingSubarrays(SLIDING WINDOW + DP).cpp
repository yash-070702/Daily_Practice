#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int n;
    vector<int>prefix;

    int solve(int i , int j , vector<int>&nums , int len){
        if(j-i+1<len)
        return 0;
        
        int currSum;

        if(i!=0)
         currSum=prefix[i+len-1]-prefix[i-1];

         else
         currSum=prefix[i+len-1];


         for(int x=i+len;x<=j;x++){
            int curr=prefix[x]-prefix[x-len];
            currSum=max(currSum,curr);
         }
       return currSum;

    }

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        n=nums.size();
        prefix.resize(n);
        prefix[0]=nums[0];

        int ans=0;
        
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }

        int currSum=prefix[firstLen-1];
        int prevSum=0;
        int nextSum=solve(firstLen+1,n-1,nums,secondLen);
        int curr=currSum+max(prevSum,nextSum);
        ans=max(ans,curr);
    

        for(int i=firstLen;i<n;i++){
             currSum=prefix[i]-prefix[i-firstLen];

             prevSum=solve(0,i-firstLen,nums,secondLen);
             nextSum=solve(i+1,n-1,nums,secondLen);

              curr=currSum+max(prevSum,nextSum);
              ans=max(ans,curr);
        }

        return ans;
    }
};