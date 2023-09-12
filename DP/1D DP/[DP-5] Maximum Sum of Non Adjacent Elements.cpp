#include <bits/stdc++.h> 


//                r e c u r s i v e   +  m e m o i z e 
/*
int f(int idx,vector<int>& nums,vector<int>&dp)
{
    if(idx==0)return nums[0];
    // if(idx==1)return dp[1]=nums[1];   cant write this. just think wh?????
    if(idx<0)return 0;

    if(dp[idx]!=-1)return dp[idx];

    //do all the stuffs
    int pick=nums[idx] + f(idx-2,nums,dp);
    int notPick=0 + f(idx-1,nums,dp);
    
    return dp[idx]=max(pick,notPick);
}


int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    vector<int>dp(n,-1);
    return f(n-1,nums,dp);
    //f(...) returns  the min sum to reach final pos
}
*/

//            t a b u l a t i o n 

/*
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    if (n == 0) 
        return 0; 


    vector<int>dp(n);
    dp[0]=nums[0];

    for (int i = 1; i <= n - 1; i++) {
      int pick = nums[i];
      if (i > 1)
        pick += dp[i - 2];
      int notPick = 0 + dp[i - 1];
      dp[i] = max(pick, notPick);
    }
    return dp[n - 1];
    
    //dp[i] stores  the min sum to reach 0 to i
}
*/








// s p a c e   o p t i m i z a t i o n 


int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    if (n == 0)return 0; 

    int prev2=0;
    int prev1=nums[0];
    int curri;

    for (int i = 1; i <= n - 1; i++) {
      int pick = nums[i];
      if (i > 1)
        pick += prev2;
      int notPick = 0 + prev1;
      curri = max(pick, notPick);

      prev2=prev1;
      prev1=curri;
    }
    return prev1;
}