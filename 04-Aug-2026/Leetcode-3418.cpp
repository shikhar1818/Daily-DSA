class Solution {
public:
int solve(vector<vector<int>>& coins, int i , int j , int cnt, int m , int n,vector<vector<vector<int>>> &dp){
    if(i >= m || j >= n)
    return -1e9;

    if(i==m-1 && j==n-1){
    if(coins[i][j] >= 0)
        return dp[i][j][cnt] = coins[i][j];

    if(cnt)
        return dp[i][j][cnt] = max(0, coins[i][j]);

    return dp[i][j][cnt] = coins[i][j];
}

    if(dp[i][j][cnt] != INT_MIN)
    return dp[i][j][cnt];
    int cur = 0;

    if(coins[i][j] >= 0){
    int r = coins[i][j]+solve(coins,i+1,j,cnt,m,n,dp);
    int d = coins[i][j]+solve(coins,i,j+1,cnt,m,n,dp);
    return dp[i][j][cnt] = max(r,d);
    }
    int tr = -1e9;
    int td = -1e9;
        if(cnt){
         tr = solve(coins,i+1,j,cnt-1,m,n,dp);
         td =  solve(coins,i,j+1,cnt-1,m,n,dp);
        }
        int ntr = coins[i][j]+solve(coins,i+1,j,cnt,m,n,dp);
        int ntd =  coins[i][j]+solve(coins,i,j+1,cnt,m,n,dp);

    return dp[i][j][cnt] = max(tr,max(td,max(ntr,ntd)));

}
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(3,INT_MIN)));
        return solve(coins,0,0,2,m,n,dp);
        
    }
};