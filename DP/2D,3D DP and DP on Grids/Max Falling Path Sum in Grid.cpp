#include <bits/stdc++.h> 
// //recursively

// //TC-O( mX  3^(n))
// //SC-O( n)

// //f(i,j) -> max sum to reach (i,j) from (first row)
// int f(int i, int j, vector<vector<int>> &mat, int n, int m) {
//   if (j < 0 || i < 0 || j >= m)
//     return INT_MIN; // inValid path

//   if (i == 0 && (j >= 0 && j < m))
//     return mat[0][j];

//   // do all stuffs
//   int up = INT_MIN, diagLeft = up, diagRight = up;
//   if (i > 0)
//     up = f(i - 1, j, mat, n, m);
//   if (i > 0 && j > 0)
//     diagLeft = f(i - 1, j - 1, mat, n, m);
//   if (i > 0 && j < m)
//     diagRight = f(i - 1, j + 1, mat, n, m);

//   return max(up, max(diagLeft, diagRight)) + mat[i][j];
// }

// int getMaxPathSum(vector<vector<int>> &mat)
// {
//     int n=mat.size();//rows
//     int m=mat[0].size();//cols

//     //f(n-1,3) -> max sum to reach (n-1,4) from (first row)

//     int ans=INT_MIN;
//     for (int j = 0; j < m; j++) // O(m)
//     {
//         ans = max(ans, f(n - 1, j, mat, n, m));
//     }
//     return ans;
// }














// //memoize

// //TC-O( n*m )
// //SC-O(n)+ O(n*m)

// //f(i,j) -> max sum to reach (i,j) from (first row)
// int f(int i, int j, vector<vector<int>> &mat, int n, int m,vector<vector<int>>&dp) {
//   if (j < 0 || i < 0 || j >= m)
//     return INT_MIN; // inValid path

//   if (i == 0 && (j >= 0 && j < m))
//     return mat[0][j];
//   if(dp[i][j]!=-1)return dp[i][j];

//   // do all stuffs
//   int up = INT_MIN, diagLeft = up, diagRight = up;
//   if (i > 0)
//     up = f(i - 1, j, mat, n, m,dp);
//   if (i > 0 && j > 0)
//     diagLeft = f(i - 1, j - 1, mat, n, m,dp);
//   if (i > 0 && j < m)
//     diagRight = f(i - 1, j + 1, mat, n, m,dp);

//   return dp[i][j]=max(up, max(diagLeft, diagRight)) + mat[i][j];
// }

// int getMaxPathSum(vector<vector<int>> &mat)
// {
//     int n=mat.size();//rows
//     int m=mat[0].size();//cols
//     vector<vector<int>>dp(n,vector<int>(m,-1));
//     //f(n-1,3) -> max sum to reach (n-1,4) from (first row)

//     int ans=INT_MIN;
//     for (int j = 0; j < m; j++) // O(m)
//     {
//         ans = max(ans, f(n - 1, j, mat, n, m,dp));
//     }
//     return ans;
// }











// //tab

// //TC-O( n*m )+O(m)
// //SC-O(n)+ O(n*m)


// int getMaxPathSum(vector<vector<int>> &mat)
// {
//     int n=mat.size();//rows
//     int m=mat[0].size();//cols
//     vector<vector<int>>dp(n,vector<int>(m));

//     for(int j=0;j<m;j++)//base case - first row
//       dp[0][j]=mat[0][j];
    
//     for(int i=1;i<n;i++)
//     {
//       for (int j = 0; j < m; j++) {
        
//         // do all stuffs
//         int diagLeft =INT_MIN, diagRight = INT_MIN;
//         int up = dp[i-1][j];
//         if (j > 0)
//           diagLeft = dp[i-1][j-1];
//         if (j+1 < m)
//           diagRight = dp[i-1][j+1];
        
//         dp[i][j]=max(up,max(diagLeft,diagRight))+mat[i][j];
//       }
//     }
//     int ans=dp[n-1][0];
//     for(int j=1;j<m;j++)
//       ans=max(ans,dp[n-1][j]);
//     return ans;
// }









//space optimized

//TC-O( n*m )+O(m)
//SC-O(m)


int getMaxPathSum(vector<vector<int>> &mat)
{
    int n=mat.size();//rows
    int m=mat[0].size();//cols
    
    vector<int>prev=mat[0];//base case- first row

    for(int i=1;i<n;i++)
    {
      vector<int>curr(m);
      for (int j = 0; j < m; j++) 
      {  
        // do all stuffs
        int diagLeft =INT_MIN, diagRight = INT_MIN;
        int up = prev[j];
        if (j > 0)
          diagLeft = prev[j-1];
        if (j+1 < m)
          diagRight = prev[j+1];
        
        curr[j]=max(up,max(diagLeft,diagRight))+mat[i][j];
      }
      prev=curr;
    }
    int ans=prev[0];
    for(int j=1;j<m;j++)
      ans=max(ans,prev[j]);
    return ans;
}