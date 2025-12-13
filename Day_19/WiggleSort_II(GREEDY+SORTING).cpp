#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(nums.begin(),nums.end());
        sort(result.begin(),result.end());

        int mid=(n-1)/2;

        int i=mid;
        int j=n-1;
        int a=0;

        while(a<n){
            nums[a]=result[i];
            i--;
            a++;

            if(a<n)
            {
                nums[a]=result[j];
                a++;
                j--;
            }
        }
    }
};