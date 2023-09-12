#include <bits/stdc++.h>

// memoiz soln


// tc!= 2^(mXn) exponential tc in rec based soln
//tc- (mXn)
// sc-O(mXn) + O(path length) - due to rec stack space
// int f(int i , int j,vector<vector<int>>&dp)
// {
//     if(i==0 && j==0)return 1;
//     if(i<0 || j<0)return 0;

//     if(dp[i][j]!=-1)return dp[i][j];
    
//     int up=f(i-1,j,dp);
//     int left=f(i,j-1,dp);

//     return dp[i][j]=up+left;
// }

// int uniquePaths(int m, int n) {
//     vector<vector<int>>dp(m,vector<int>(n,-1));
//     return f(m-1,n-1,dp);//m rows, n cols
// }








//tabulate -bottom up aproach


// tc!= 2^(mXn) exponential tc in rec based soln
//tc- (mXn) same
// sc-O(mXn)

// int uniquePaths(int m, int n) {
//     vector<vector<int>>dp(m,vector<int>(n,1));
//     for(int i=1;i<=m-1;i++)
//     {
//         for(int j=0;j<=n-1;j++){
//             int left=0;
//             if(j>0)left=dp[i][j-1];
//             dp[i][j]=dp[i-1][j]+left;
//         }
//     }
//     return dp[m-1][n-1];
// }






//space opti solution

int uniquePaths(int m, int n) {
    
    vector<int>prev(n,1);
    for(int i=1;i<=m-1;i++)
    {   vector<int>curr(n,0);
        for(int j=0;j<=n-1;j++){
            int left=0;
            if(j>0)
                left=curr[j-1];    
            curr[j]=left+prev[j];
        }
        prev=curr;
    }
    return prev.back();
}


















/*
   // The Most OPTIMAL : using combination
    int steps=(m-1)+(n-1); //path length
    int r=m-1;//no of rights
    double res=1;

    for(int i=1; i<=r; i++)
    {
        // res = res * (steps - r + i) / i;
        res=res* (steps)/i ;
        steps=steps-1;
    }
    
    return (int)res;
*/