#include <bits/stdc++.h> 
//ONLY RECURSION

int solveRec(int idx,vector<int> &h)
{
    if(idx==0) return 0;
    if(idx==1) return (abs(h[1]-h[0]));

    int left=solveRec(idx-1,h) + abs(h[idx]-h[idx-1]);
    int right=solveRec(idx-2,h) + abs(h[idx]-h[idx-2]);

    return min(left,right);
}




// MEMOIZATION
int recMemoi(int idx,vector<int> &h,vector<int>&dp)
{
    if(idx==0) return 0;
    if(idx==1) return dp[1]=(abs(h[1]-h[0]));

    if(dp[idx]!=-1) return dp[idx];

    int left=recMemoi(idx-1,h,dp) + abs(h[idx]-h[idx-1]);
    int right=recMemoi(idx-2,h,dp) + abs(h[idx]-h[idx-2]);

    return dp[idx]=min(left,right);
}

//TABULATON
void tab(int n, vector<int> &h,vector<int> &dp)
{
    dp[0]=0;
    dp[1]=abs(h[0]-h[1]);
    for (int i = 2; i <= n; i++) {
      int l = dp[i - 1] + abs(h[i] - h[i - 1]);
      int r = dp[i - 2] + abs(h[i] - h[i - 2]);
      dp[i] = min(l, r);
    }
} 
*/
int frogJump(int n, vector<int> &heights)
{
    // return solveRec(n-1,heights);
    
    // vector<int>dp(n+1,-1);
    // return recMemoi(n-1,heights,dp);
    
    // tab(n-1,heights,dp);
    // return dp[n-1];

    //space optimised
    int prev2=0;
    int prev1=abs(heights[0]-heights[1]);
    int curr;

    for (int i = 2; i <= n - 1; i++) {
      int l = prev1 + abs(heights[i] - heights[i - 1]);
      int r = prev2 + abs(heights[i] - heights[i - 2]);
      curr = min(l, r);
      prev2 = prev1;
      prev1 = curr;
    }
    return curr;

}