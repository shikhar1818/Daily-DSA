class Solution {
public:
    int fun(string &s, string &t, int i, int j,vector<vector<int>> &dp){
        if(i < 0)
        return j < 0;
        if(j < 0)
        return 1;

        if(dp[i][j] != -1)
        return dp[i][j];

        int take = 0,nottake = 0;
        if(s[i] == t[j])
        take = fun(s,t,i-1,j-1,dp);

        nottake = fun(s,t,i-1,j,dp);

        return dp[i][j] = take+nottake;
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return fun(s,t,n-1,m-1,dp);
    }
};



// approach 2
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                unsigned long long take = 0, nottake = 0;
                if (s[i - 1] == t[j - 1])
                    take = dp[i - 1][j - 1];

                nottake = dp[i - 1][j];
                dp[i][j] = take + nottake;
            }
        }
        
        return (int)dp[n][m];
    }
};
