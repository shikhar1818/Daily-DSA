class Solution {
public:
    int solve(int n, int i,vector<vector<int>> &dp){
        if(n == 0)
        return 0;
        if(i == 1)
        return n;

        if(dp[n][i] != -1)
        return dp[n][i]; 

        int t = 1e9,nt = 1e9;
        if(i*i <= n)
            t = 1 + solve((n-(i*i)),i,dp);

        nt = solve(n,i-1,dp);
        return dp[n][i] = min(t,nt);
    }
    int numSquares(int n) {
        int i = (int)sqrt(n);
        vector<vector<int>> dp(n+1,vector<int>(i+1,-1));
        return solve(n,i,dp);
    }
};