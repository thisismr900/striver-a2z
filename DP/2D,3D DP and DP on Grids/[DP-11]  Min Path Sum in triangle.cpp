//rec
#include <bits/stdc++.h> 
// int recfun(int i, int j, vector<vector<int>>& triangle, int n)
// {
// 	//base case
// 	if(i==n-1)
// 		return triangle[n-1][j];

// 	int lower=recfun(i+1,j,triangle,n);
// 	int diag=recfun(i+1,j+1,triangle,n);

// 	return min(lower,diag)+triangle[i][j];	
// }
// int minimumPathSum(vector<vector<int>>& triangle, int n){
// 	return recfun(0,0,triangle,n);
// }




//memoi
//tc-O(nXn)
//sc-O(nXn) due to dp[n][n] + O(n) due to rec stack space
// int memoi(int i, int j, vector<vector<int>>& triangle, int n,vector<vector<int>>&dp)
// {
// 	//base case
// 	if(i==n-1)
// 		return triangle[n-1][j];

// 	//see if already calculated
// 	if(dp[i][j]!=-1)return dp[i][j];
	
// 	int lower=memoi(i+1,j,triangle,n,dp)+triangle[i][j];
// 	int diag=memoi(i+1,j+1,triangle,n,dp)+triangle[i][j];

// 	return dp[i][j]=min(lower,diag);	
// }
// int minimumPathSum(vector<vector<int>>& triangle, int n){
// 	vector<vector<int>>dp(n,vector<int>(n,-1));
// 	return memoi(0,0,triangle,n,dp);
// }






// //tabulation base approach
// //tc-O(nXn)
// //sc-O(nXn)

// void tab(int i, int j, vector<vector<int>>& triangle, int n,vector<vector<int>>&dp)
// {
// 	//base case- at bottom row
// 	for(int j=0;j<n;j++)
// 		dp[n-1][j]=triangle[n-1][j];
	
// 	for(int i=n-2;i>=0;i--)
// 	{
// 		for(int j=i;j>=0;j--){
// 			int down=dp[i+1][j];
// 			int diag=dp[i+1][j+1];

// 			dp[i][j]=min(down,diag)+triangle[i][j];
// 		}
// 	}
// }
// int minimumPathSum(vector<vector<int>>& triangle, int n){
// 	vector<vector<int>>dp(n,vector<int>(n,-1));
// 	tab(0,0,triangle,n,dp);
// 	return dp[0][0];
// }









//space opt
//tc-O(nXn)
//sc-O(n)

int spaceOpt(int i, int j, vector<vector<int>>& triangle, int n)
{
	//base case- at bottom row
	vector<int>bottom=triangle[n-1];//the last row

	for(int i=n-2;i>=0;i--)
	{
		vector<int>curr(n);
		for(int j=i;j>=0;j--){
			int down=bottom[j];
			int diag=bottom[j+1];

			curr[j]=min(down,diag)+triangle[i][j];
		}
		bottom=curr;
	}
	//i=-1
	return bottom[0];
}
int minimumPathSum(vector<vector<int>> &triangle, int n) {
        return spaceOpt(0, 0, triangle, n);
}

