// Memoization
int help(int n, vector<int> &height,vector<int> &dp){
    if(n<0){
        return 1e9;
    }
    if(n==0)
        return 0;
    if(dp[n]!=-1)
        return dp[n];
    return dp[n]=min(help(n-1,height,dp)+abs(height[n]-height[n-1]),
                            help(n-2,height,dp)+abs(height[n]-height[n-2]));
}

// Tabulation
int frogJump(int n, vector<int> &height)
{
    int dp[n];
    dp[0]=0;
    for(int i=1;i<n;i++){
        int first=dp[i-1]+abs(height[i]-height[i-1]);
        int second=1e9;
        if(i>1){
            second=dp[i-2]+abs(height[i]-height[i-2]);
        }
        dp[i]=min(first,second);
    }
    return dp[n-1];
}

// Space optimization
int frogJump(int n, vector<int> &height)
{
    int dp[n];
    dp[0]=0;
    int prev=0,prev2=0,curr;
    for(int i=1;i<n;i++){
        int first=prev+abs(height[i]-height[i-1]);
        int second=1e9;
        if(i>1){
            second=prev2+abs(height[i]-height[i-2]);
        }
        curr=min(first,second);
        prev2=prev;
        prev=curr;
    }
    return curr;
}