//memoization

// int f(int idx,int k,vector<int>&h,vector<int>&dp)
// {
//     if(idx==0)return 0;

//     if(dp[idx]!=-1)return dp[idx];


//     int minEnergy=INT_MAX;
//     //do all the possible stuffs/jumps
//     for(int j=1;j<=k;j++)
//     {
//         if(idx-j >=0){
//             int jumpEnergy=f(idx-j,k,h,dp)+abs(h[idx]-h[idx-j]);
//             minEnergy=min(minEnergy,jumpEnergy);
//         }
            
//     }
//     return dp[idx]=minEnergy;
// }
// int minimizeCost(int n, int k, vector<int> &h){
//     vector<int>dp(n,-1);
//     return f(n-1,k,h,dp);
// }



//T A B U L A T I O N
int f(int idx,int k,vector<int>&h,vector<int>&dp)
{
    if(idx==0)return 0;

    if(dp[idx]!=-1)return dp[idx];


    int minEnergy=INT_MAX;
    //do all the possible stuffs/jumps
    for(int j=1;j<=k;j++)
    {
        if(idx-j >=0){
            int jumpEnergy=f(idx-j,k,h,dp)+abs(h[idx]-h[idx-j]);
            minEnergy=min(minEnergy,jumpEnergy);
        }
            
    }
    return dp[idx]=minEnergy;
}
int minimizeCost(int n, int k, vector<int> &h){
    vector<int>dp(n,-1);
    // return f(n-1,k,h,dp);
    dp[0]=0;

    for(int i=1;i<n;i++)
    {
        int minEnergy=INT_MAX;
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
            {
                int jEnergy=dp[i-j]+abs(h[i]-h[i-j]);
                minEnergy=min(jEnergy,minEnergy);
            }
        }
        dp[i]=minEnergy;
    }
    return dp[n-1];
}