#include <bits/stdc++.h> 

//recursive
//TC-O(3^n  *  3^n  )
//SC-O(n) //aux stack space
// int rec(int i, int j1,int j2, vector<vector<int>>&grid,int r, int c)
// {
//     //out of bound base cases
//     if(j1<0 || j1>=c ||j2<0 || j2>=c)
//         return -1e8;
//     //destination base case
//     if(i==r-1){
//         if(j1==j2)
//             return grid[i][j1];
//         else    
//             return grid[i][j1]+grid[i][j2];
//     }

//     int maxi=0;
//     for(int dj1=-1;dj1<=1;dj1++)
//     {
//         for(int dj2=-1;dj2<=1;dj2++)
//         {
//             if(j1==j2)
//                maxi=max(maxi,rec(i,j1+dj1,j2+dj2,grid,r,c))+grid[i][j1];
//             else
//                 maxi=max(maxi,rec(i,j1+dj1,j2+dj2,grid,r,c))+grid[i][j1]+grid[i][j2];
//         }
//     }
//     return maxi;
// }





//memoize
//TC-O(  )
//SC-O() 
// int memoi(int i, int j1,int j2, vector<vector<int>>&grid,int r, int c,vector<vector<vector<int>>>&dp)
// {
//     //out of bound base cases
//     if(j1<0 || j1>=c ||j2<0 || j2>=c)
//         return -1e8;
//     //destination base case
//     if(i==r-1){
//         if(j1==j2)
//             return grid[i][j1];
//         else    
//             return grid[i][j1]+grid[i][j2];
//     }

//     if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
//     int maxi=0;
//     for(int dj1=-1;dj1<=1;dj1++)
//     {
//         for(int dj2=-1;dj2<=1;dj2++)
//         {
//             int val;
//             if(j1+dj1==j2+dj2)
//                val=grid[i][j1];
//             else
//                 val=grid[i][j1]+grid[i][j2];
            
//             val+=memoi(i+1,j1+dj1,j2+dj2,grid,r,c,dp);
//             maxi=max(val,maxi);
//         }
//     }
//     return dp[i][j1][j2]=maxi;
// }





//tabulation
//TC-O(n*m*m)*9
//SC-O(n*m*m)

// int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
//     vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m)));
//     // return memoi(0,0,c-1,grid,r,c,dp);

//     //base case analysis
//     //i=r-1
//     for(int j1=0;j1<m;j1++)
//     {
//         for(int j2=0;j2<m;j2++){
//             if(j1==j2)
//                 dp[n-1][j1][j2]=grid[n-1][j1];
//             else
//                 dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
//         }
//     }

//     for(int i=n-2;i>=0;i--)
//     {
//         for(int j1=0;j1<m;j1++)
//         {
//             for(int j2=0;j2<m;j2++)
//             {
                
//                 int maxi=-1e8;
//                 for(int dj1=-1;dj1<=1;dj1++)
//                 {
//                     for(int dj2=-1;dj2<=1;dj2++)
//                     {   
//                     int val=0;
//                     if(j1==j2)
//                         val=grid[i][j1];
//                     else
//                         val=grid[i][j1]+grid[i][j2];
//                     if(j1+dj1 >=0 && j1+dj1<m && j2+dj2>0 && j2+dj2<m)
//                         val+=dp[i+1][j1+dj1][j2+dj2];
//                     else val=-1e8;
//                     maxi=max(val,maxi);

//                     }
//                 }
//                     dp[i][j1][j2]=maxi;   
//             }
//         }
//     }
//     return dp[0][0][m-1];
// }






//space opti
//TC-O(n*m*m)*9
//SC-O(m*m)

int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    
    vector<vector<int>>prev(m,vector<int>(m));
    
    //base case analysis
    //i=r-1
    for(int j1=0;j1<m;j1++)
    {
        for(int j2=0;j2<m;j2++){
            if(j1==j2)
                prev[j1][j2]=grid[n-1][j1];
            else
                prev[j1][j2]=grid[n-1][j1]+grid[n-1][j2];
        }
    }

    for(int i=n-2;i>=0;i--)
    {
        vector<vector<int>>curr(m,vector<int>(m));
        for(int j1=0;j1<m;j1++)
        {
            for(int j2=0;j2<m;j2++)
            {
                
                int maxi=-1e8;
                for(int dj1=-1;dj1<=1;dj1++)
                {
                    for(int dj2=-1;dj2<=1;dj2++)
                    {   
                    int val=0;
                    if(j1==j2)
                        val=grid[i][j1];
                    else
                        val=grid[i][j1]+grid[i][j2];
                    if(j1+dj1 >=0 && j1+dj1<m && j2+dj2>0 && j2+dj2<m)
                        val+=prev[j1+dj1][j2+dj2];
                    else val=-1e8;
                    maxi=max(val,maxi);

                    }
                }
                    curr[j1][j2]=maxi;   
            }
        }
        prev=curr;
    }
    return prev[0][m-1];
}