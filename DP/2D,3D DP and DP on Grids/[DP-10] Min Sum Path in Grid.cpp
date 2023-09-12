


#include <bits/stdc++.h> 

//recursion

// int rec(int i, int j, vector<vector<int>> &grid)
// {
//     if(i==0 && j==0)return grid[0][0];
//     if(i<0 || j<0)return INT_MAX;

//     int upperSum=rec(i-1,j,grid);
//     int lowerSum=rec(i,j-1,grid);

//     return min(lowerSum,upperSum)+grid[i][j];
// }

// int minSumPath(vector<vector<int>> &grid) {
//     int n=grid.size();
//     int m=grid[0].size();
//     return rec(n-1,m-1,grid);
// }



//rec + memoization


// int recMem(int i, int j, vector<vector<int>> &grid,vector<vector<int>>&dp)
// {
//     if(i==0 && j==0)return grid[0][0];
//     if(i<0 || j<0)return INT_MAX;

//     if(dp[i][j]!=-1)return dp[i][j];

//     int upperSum=recMem(i-1,j,grid,dp);
//     int lowerSum=recMem(i,j-1,grid,dp);

//     return dp[i][j]=min(lowerSum,upperSum)+grid[i][j];
// }

// int minSumPath(vector<vector<int>> &grid) {
//     int n=grid.size();
//     int m=grid[0].size();
//     vector<vector<int>>dp(n,vector<int>(m,-1));
//     return recMem(n-1,m-1,grid,dp);
// }




//tabulation
// void tab(int i, int j, vector<vector<int>> &grid,vector<vector<int>>&dp,int n, int m)
// {
//     dp[0][0]=grid[0][0];
//     // if(i<0 || j<0)return INT_MAX;

//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             if(i==0 && j==0)
//                 dp[0][0]=grid[0][0];
//             else{    
//                 int upperSum=INT_MAX,leftSum=INT_MAX;
//                 if(i>0)upperSum=dp[i-1][j];
//                 if(j>0)leftSum=dp[i][j-1];

//                 dp[i][j]=grid[i][j]+ min(upperSum,leftSum);
//             }
//         }
//     }
// }

// int minSumPath(vector<vector<int>> &grid) {
//     int n=grid.size();
//     int m=grid[0].size();
//     vector<vector<int>>dp(n,vector<int>(m,-1));
//     tab(n-1,m-1,grid,dp,n,m);
//     return dp[n-1][m-1];
// }




//space optimised
// sc-O(m)
// tc-O(nXm)
// void tab(vector<vector<int>> &grid,vector<int>&prev,int m)
// {
//     int n=grid.size();
//     for(int i=0;i<n;i++)
//     {
//         vector<int>curr(m,0);
//         for(int j=0;j<m;j++)
//         {
//             if(i==0 && j==0)
//                 prev[0]=grid[0][0];
//             else{    
//                 int upperSum=INT_MAX,leftSum=INT_MAX;
//                 if(i>0)upperSum=prev[j];
//                 if(j>0)leftSum=curr[j-1];

//                 curr[j]=grid[i][j]+ min(upperSum,leftSum);
//             }
//         }
//         prev=curr;
//     }
// }

// int minSumPath(vector<vector<int>> &grid){
//     int m=grid[0].size();
//     vector<int>prev(m,INT_MAX);
//     tab(grid,prev,m);
//     return prev[m-1];
// }




//here we distort the grid 
// sc-O(1)
// tc-O(nXm)
#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n=grid.size();
    int m=grid[0].size();
    for(int i=1;i<m;i++){
        grid[0][i]+=grid[0][i-1];
    }
    for(int i=1;i<n;i++){
        grid[i][0]+=grid[i-1][0];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
        }
    }
    return grid[n-1][m-1];
}


