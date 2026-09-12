class Solution {
public:
int fun(vector<int>& prices,int i,int j,int k,int n,vector<vector<vector<int>>> &dp){
    if(i == n || k == 0){
        return 0;
    }

    if(dp[i][j][k] != -1)
    return dp[i][j][k];

    if(!j)
       dp[i][j][k] = max((-prices[i]+fun(prices,i+1,1,k,n,dp)),fun(prices,i+1,0,k,n,dp));
    else
       dp[i][j][k] = max((prices[i]+fun(prices,i+1,0,k-1,n,dp)),fun(prices,i+1,1,k,n,dp));

    return dp[i][j][k];
}
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return fun(prices,0,0,k,n,dp);
        
    }
};