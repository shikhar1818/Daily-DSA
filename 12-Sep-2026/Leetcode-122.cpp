class Solution {
public:
int fun(vector<int>& prices,int i,int j,int n,vector<vector<int>> &dp){
    if(i == n){
        return 0;
    }

    if(dp[i][j] != -1e9)
    return dp[i][j];

    if(!j)
       dp[i][j] = max((-prices[i]+fun(prices,i+1,1,n,dp)),fun(prices,i+1,0,n,dp));
    else
       dp[i][j] = max((prices[i]+fun(prices,i+1,0,n,dp)),fun(prices,i+1,1,n,dp));

    return dp[i][j];
}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1e9));
        return fun(prices,0,0,n,dp);
    }
};