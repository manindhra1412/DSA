// Memoisation
class Solution {
public:
    int fib(int n,int dp[]) {
        if(n==0 || n==1)
            return n;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n]=fib(n-1,dp)+fib(n-2,dp);
    }
};

//  Tabulation
class Solution {
public:
    int fib(int n) {
        int dp[n];
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

//  Space Optimization
class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1) return n;
        int prev1=0,prev2=1,curr;
        for(int i=2;i<=n;i++){
            curr=prev1+prev2;
            prev1=prev2; prev2=curr;
        }
        return curr;
    }
};