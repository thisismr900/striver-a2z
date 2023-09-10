#include <bits/stdc++.h> 
long long solve(vector<int>& val)
{
       
	long long prev2=0,prev=val[0],curri;
    int n=val.size();
    for (int i = 1; i <= n - 1; i++) 
    {
        long long looted = val[i];
        if (i > 1)
            looted += prev2;
        long long notLooted = 0 + prev;

        curri = max(looted, notLooted);

        prev2 = prev;
        prev = curri;
    }
        return prev;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    int n=valueInHouse.size();
    if(n==1)return valueInHouse[0];
    if(n==0|| n==2)return 0;
    int first=valueInHouse[0];
    int last=valueInHouse[n-1];

    valueInHouse[0]=0;
    long long ans1=solve(valueInHouse);
    valueInHouse[0]=first;

    valueInHouse[n-1]=0;
    long long ans2=solve(valueInHouse);
    valueInHouse[n-1]=last;

    return max(ans1,ans2);
}
