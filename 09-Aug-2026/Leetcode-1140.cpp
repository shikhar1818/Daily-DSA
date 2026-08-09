class Solution {
public:
    int solve(int i, int n, vector<int>& piles, int m, bool alice,
              vector<vector<vector<int>>>& dp) {

        if (i >= n)
            return 0;

        if (dp[i][m][alice] != -1)
            return dp[i][m][alice];

        int ans = alice ? 0 : INT_MAX;
        int cur = 0;

        for (int x = 1; x <= 2 * m && i + x <= n; x++) {
            cur += piles[i + x - 1];

            if (alice) {
                ans = max(ans,
                          cur + solve(i + x, n, piles, max(x, m), false, dp));
            } else {
                ans = min(ans, solve(i + x, n, piles, max(x, m), true, dp));
            }
        }

        return dp[i][m][alice] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2 * n + 1, vector<int>(2, -1)));
        return solve(0, n, piles, 1, true, dp);
    }
};