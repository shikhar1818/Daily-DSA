class Solution {
public:
    int fun(int n, int i, int k, int f,vector<vector<vector<int>>> &dp,int &mod){
        if(i >= n)
        return 0;
        if(k == 0)
        return 1;

        if(dp[i][k][f] != -1)
        return dp[i][k][f];

        int ans = 0;
        ans += (fun(n,i+1,k,1,dp,mod)%mod);

        if(f)
        ans += (fun(n,i,k-1,0,dp,mod)%mod);
        else
        ans += (fun(n,i+1,k,0,dp,mod)%mod);

        return dp[i][k][f] = (ans)%mod;
    }
    int numberOfSets(int n, int k) {
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
        int mod = 1e9+7;
        return fun(n,0,k,0,dp,mod);
        
    }
};