//recursive + memoization
// int solveMem(int i,int j,vector< vector< int> > &mat,vector<vector<int>>&dp)
// {
//     //base cases
//     if(i==0 && j==0)
//         return 1;//got a valid unique path
//     if(i<0 || j<0)return 0;//invalid path
//     if(mat[i][j]==-1)return 0; //blocked path

//     if(dp[i][j]!=-1)return dp[i][j];
//     //do all stuff on current cell
//     int up=solveMem(i-1,j,mat,dp);
//     int left=solveMem(i,j-1,mat,dp);

//     return dp[i][j]=(up+left)%(1000000007);
// }

// int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
//     // Write your code here
//     // return solveRec(n-1,m-1,mat);
//     vector<vector<int>>dp(n,vector<int>(m,-1));
//     return solveMem(n-1,m-1,mat,dp);
// }


//TABULATION


int solveMem(int i,int j,vector< vector< int> > &mat,vector<vector<int>>&dp)
{
    //base cases
    if(i==0 && j==0)
        return 1;//got a valid unique path
    if(i<0 || j<0)return 0;//invalid path
    if(mat[i][j]==-1)return 0; //blocked path

    if(dp[i][j]!=-1)return dp[i][j];
    //do all stuff on current cell
    int up=solveMem(i-1,j,mat,dp);
    int left=solveMem(i,j-1,mat,dp);

    return dp[i][j]=(up+left)%(1000000007);
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>>dp(n,vector<int>(m));
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 && j==0)dp[0][0]=1;
    
            else if(mat[i][j]==-1)dp[i][j]=0;

            else {
              int up = 0, left = 0;
              if (i > 0)
                up = dp[i - 1][j];
              if (j > 0)
                left = dp[i][j - 1];

              dp[i][j] = (up + left) % 1000000007;
            }
        }
    }
    return dp[n-1][m-1];
}


