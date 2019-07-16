#include <bits/stdc++.h>
using namespace std;
int value(int cap[],int ass[],int n,int dif,int** dp)
{
    if(n==0)
        return 0;
    if(dp[n][dif]!=-1)
        return dp[n][dif];
    if(dif==0)
    {
        dp[n][dif]= ass[0]+value(cap+1,ass+1,n-1,dif+1,dp);
    }
    else if(dif==n)
    {
        dp[n][dif]= cap[0]+value(cap+1,ass+1,n-1,dif-1,dp);
    }
    else
    {
        dp[n][dif]= min(ass[0]+value(cap+1,ass+1,n-1,dif+1,dp),cap[0]+value(cap+1,ass+1,n-1,dif-1,dp));
    }
    return dp[n][dif];
}
int main()
{
    int n;
    cin>>n;
    int cap[n],ass[n];
    for(int i=0;i<n;i++)
    {
        cin>>cap[i]>>ass[i];
    }
    int **dp= new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]= new int[n+1];
        for(int j=0;j<=n;j++)
            dp[i][j]=-1;
    }
    cout<<value(cap,ass,n,0,dp);
    return 0;
}
