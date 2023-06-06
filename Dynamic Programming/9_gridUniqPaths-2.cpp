// Memoisation
int solve(int i,int j,vector<vector< int>>&mat,vector<vector<int>>&dp){
    if(i>=0 && j>=0 && mat[i][j]==-1) return 0;
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int x=solve(i-1,j,mat,dp);
    int y=solve(i,j-1,mat,dp);
    return dp[i][j]=(x%mod+y%mod)%mod;
}

// Tabulation
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    int t[n][m];
     t[0][0]=1;
  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          if(mat[i][j]==-1){
              t[i][j]=0;
              continue;
          }
          if(i==0 && j==0) continue;
          int x=0,y=0;
          if(i>0)
              x=t[i-1][j];
          if(j>0)
              y=t[i][j-1];
          t[i][j]=(x%mod+y%mod)%mod;
      }
  }
    return t[n-1][m-1];
}