// Memoisation
int help(int n,int i,vector<vector<int>> &points,vector<vector<int>>&dp){
    if(n==0){
        int maxi=-1e9;
        for(int j=0;j<=2;j++){
            if(j!=i){
                maxi=max(maxi,points[n][j]);
            }
        }
        return maxi;
    }
    
    if(dp[n][i]!= -1){
        return dp[n][i];
    }

    int maxi=-1e9;
    for(int j=0;j<=2;j++){
        if(j!=i){
            maxi=max(maxi,points[n][j]+help(n-1,j,points,dp));
        }
    }
    return dp[n][i]=maxi;
}

//  Tabulation
int ninjaTraining(int n, vector<vector<int>> &points){
    int dp[n][4];
    
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][0],points[0][1]);
    dp[0][3]=max(points[0][1],max(points[0][2],points[0][0]));
    for(int i=1;i<n;i++){
        for(int j=0;j<=3;j++){
            dp[i][j]=0;
            for(int k=0;k<=2;k++){
                if(k!=j){
                    int point=points[i][k]+dp[i-1][k];
                    dp[i][j]=max(dp[i][j],point);
                }
            }
        }
    }
    return dp[n-1][3];
}