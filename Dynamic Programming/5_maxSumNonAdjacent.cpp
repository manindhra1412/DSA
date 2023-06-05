// Memoisation
int help(int n,vector<int> &nums,vector<int>&dp){
    if(n<0)
        return 0;
    if(n==0)
        return nums[0];
    if(dp[n]!=-1)
        return dp[n];
    return dp[n]=max(help(n-1,nums,dp),help(n-2,nums,dp)+nums[n]);
}

// Tabulation
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    int dp[n];
    dp[0]=nums[0];
    for(int i=1;i<n;i++){
        int adj=dp[i-1];
        int nonAdj=nums[i];
        if(i>1){
            nonAdj+=dp[i-2];
        }
        dp[i]=max(adj,nonAdj);
    }
    return dp[n-1];
}

//Space optimization
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    int prev=nums[0],prev2=0,curr;
    for(int i=1;i<n;i++){
        int adj=prev;
        int nonAdj=nums[i];
        if(i>1){
            nonAdj+=prev2;
        }
        curr=max(adj,nonAdj);
        prev2=prev;
        prev=curr;
    }
    return prev;
}