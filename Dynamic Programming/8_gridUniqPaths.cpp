// Memoisation
int solve(int i,int j,vector<vector<int>>&dp){
    if(i==0 && j==0) return 1;  
    if(dp[i][j]!=-1) return dp[i][j];
    int x=0;
    if(i>0)
        x=solve(i-1,j,dp);
    int y=0;
    if(j>0)
        y=solve(i,j-1,dp);
    return dp[i][j]=x+y;
}

// Space optimisation
int uniquePaths(int m, int n) {
//     int t[m][n];
    vector<int>prev(n,0);
    
  for(int i=0;i<m;i++){
      vector<int>curr(n,0);
      for(int j=0;j<n;j++){
          if(i==0 && j==0) curr[j]=1;
          else{
              int x=0,y=0;
          if(i>0)
              x=prev[j];
          if(j>0)
              y=curr[j-1];
          curr[j]=x+y;
      }
      }
      prev=curr;
  }
    return prev[n-1];
}