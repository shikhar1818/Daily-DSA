class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> dp(26,0);
        int mod = 1e9+7;
        int total = 0;
        for(int i = 0; i < n; i++){
            int idx = s[i]-'a';
            int ns = ((long long)total+1-dp[idx]+mod)%mod;
            total = ((long long)total+ns)%mod;
            dp[idx] = (dp[idx]+ns)%mod;
        }
        return total;
    }
};