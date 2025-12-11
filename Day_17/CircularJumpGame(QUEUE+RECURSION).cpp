#include<bits/stdc++.h>

using namespace std;

int solve(int n , int currPt , int target ,vector<int>&arr){
    if(currPt==target)
    return 0;

    if(arr[currPt]==-1)
    return INT_MAX;
    
    int currStep=arr[currPt];
    arr[currPt]=-1;

    int clockSteps=(currPt+currStep)%n;
    int clock=solve(n,clockSteps,target,arr);

    if(clock!=INT_MAX)
    clock++;

    int antiClockSteps=(n-currStep+currPt)%n;
    int antiClock=solve(n,antiClockSteps,target,arr);

    if(antiClock!=INT_MAX)
    antiClock++;


    arr[currPt]=currStep;

    return min(antiClock,clock);
}


int minJumps(int n, int x, int y, vector<int>& a) {
    int cx=x-1;
    int cy=y-1;
    
    int ans=solve(n,cx,cy,a);
    if(ans==INT_MAX)
    return -1;

    return ans;
}