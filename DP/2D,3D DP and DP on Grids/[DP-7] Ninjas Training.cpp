//recursion

#include<bits/stdc++.h>
int recFun(int day,int last,vector<vector<int>> &points)
{
    //base case
    if(day==0)
    {
        int maxMerit=0;
        for(int task=0;task<=2;task++)
        {
            int merit=0;
            if(task!=last)
            {
                merit=points[day][task];
                maxMerit=max(maxMerit,merit);
            }
        }
        return maxMerit;
    }
    //do all the stuff
    int maxMerit=0;
    for(int task=0;task<=2;task++)
    {
        int merit=0;
        if(task!=last){
            merit=points[day][task]+recFun(day-1,task,points);
            maxMerit=max(maxMerit,merit);
        }
    }
    return maxMerit;
}







//memoization
int recMem(int day,int last,vector<vector<int>> &points,vector<vector<int>>&dp)
{
    //base case
    if(day==0)
    {
        int maxMerit=0;
        for(int task=0;task<=2;task++)
        {
            int merit=0;
            if(task!=last)
            {
                merit=points[day][task];
                maxMerit=max(maxMerit,merit);
            }
        }
        return maxMerit;
    }

    if(dp[day][last]!=-1)return dp[day][last];
    
    //do all the stuff
    int maxMerit=0;
    for(int task=0;task<=2;task++)
    {
        int merit=0;
        if(task!=last){
            merit=points[day][task]+recMem(day-1,task,points,dp);
            maxMerit=max(maxMerit,merit);
        }
    }
    return dp[day][last]=maxMerit;
}


//tabulation
int tabulation(int n, vector<vector<int>> &points)
{
    // return recFun(n-1,3,points);
    
    vector<vector<int>>dp(n,vector<int>(4,-1));
    // return recMem(n-1,3,points,dp);

    //base case -for day 0
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][0],points[0][1]);
    

    for(int day=1;day<=n-1;day++){
        for(int last=0;last<=3;last++)
        {
            int maxi=0;
            for(int task=0;task<=2;task++)
            {
                if(task!=last)
                {
                    int point=points[day][task] + dp[day-1][task];
                    maxi=max(point,maxi);
                    dp[day][last]=maxi;
                }
            }   
        }
    }
    return dp[n-1][3];
}




//space opti

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int>prev(4,-1);

    //base case -for day 0
    prev[0]=max(points[0][1],points[0][2]);
    prev[1]=max(points[0][0],points[0][2]);
    prev[2]=max(points[0][0],points[0][1]);
    prev[3]=max(prev[2],points[0][2]);
    

    for(int day=1;day<=n-1;day++){
        vector<int>curr(4,0);
        for(int last=0;last<=3;last++)
        {
            int maxi=0;
            
            for(int task=0;task<=2;task++)
            {
                if(task!=last)
                {
                    int point=points[day][task] + prev[task];
                    maxi=max(point,maxi);
                    curr[last]=maxi;
                }
            }   
        }
        prev=curr;
    }
    return prev[3];
}



// dusre ka 
//Space optimisation
int SpaceOptimisation(int n, vector<vector<int>> &points)
{
    int a,b,c, d,e,f  ;
    a = points[0][0] ;
    b = points[0][1] ;
    c = points[0][2] ;
    for( int i = 1 ; i < n ; i++ )
    {
        d = points[i][0] + max(b,c) ;
        e = points[i][1] + max(a,c) ;
        f = points[i][2] + max(b,a) ;
        a = d ;
        b = e ; 
        c = f ;
    }
    return max(a, max(b,c)) ;
}