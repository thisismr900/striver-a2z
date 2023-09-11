//rec + memoization
// class Solution {
// private:
//     int solve(int idx,vector<int>& cost,vector<int>&dp)
//     {
//         if(idx<=1)return cost[idx];

//         if(dp[idx]!=-1)return dp[idx];

//         //do all the stuffs
//         int twoStep=INT_MAX;
//         int oneStep=solve(idx-1,cost,dp);
//         //0 se idx-1 tak pahuchne ka cost + n-1 se n tak pahuchne ka cost
//         if(idx-2>=0)
//         twoStep=solve(idx-2,cost,dp);
        
//         return dp[idx]=min(oneStep,twoStep)+cost[idx];    
//     }
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n=cost.size();
//         vector<int>dp(n+1,-1);
//         //no cost included at reaching the last step
        
//         return min(solve(n-1,cost,dp),solve(n-2,cost,dp));
        
//     }
// };




//tabulation
// class Solution {

// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n=cost.size();
//         vector<int>dp(n+1,-1);
//         //no cost included at reaching the last step
//         dp[0]=cost[0];
//         dp[1]=cost[1];

//         for(int i=2;i<=n-1;i++)
//         {
//             dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
//         }
//         return min(dp[n-1],dp[n-2]);
        
//     }
// };







//space opti


class Solution {

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        //no cost included at reaching the last step
        int prev2=cost[0];
        int prev=cost[1];
        int curri;

        for(int i=2;i<=n-1;i++)
        {
            curri=cost[i]+min(prev2,prev);
            prev2=prev;
            prev=curri;
        }
        return min(prev,prev2);
        
    }
};