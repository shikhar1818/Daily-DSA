class Solution {
public:
    int fun(vector<vector<int>>& grid, int i, int j, int k, int &m , int &n,int &mod,vector<vector<vector<int>>> &dp){
        if(i >= m || j >= n)
        return 0;
        if(i == m-1 && j == n-1)
        return 1;

        if(dp[i][j][k] != -1)
        return dp[i][j][k];

        int ans = 0;
        if(grid[i][j] == 0){
            ans = ((fun(grid,i+1,j,0,m,n,mod,dp)%mod)+(fun(grid,i,j+1,1,m,n,mod,dp)%mod))%mod;
        }
        else{
            if(k == 1)
            ans = fun(grid,i+1,j,0,m,n,mod,dp)%mod;
            else
            ans = fun(grid,i,j+1,1,m,n,mod,dp)%mod;
        }
        return dp[i][j][k] = ans;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int mod = 1000000007;
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(2,-1)));
        return fun(grid,0,0,0,m,n,mod,dp);
        
    }
};