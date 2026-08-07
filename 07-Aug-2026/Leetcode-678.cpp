class Solution {
public:
bool solve(int i, int cnt, int n,string &s,vector<vector<int>> &dp){
    if(cnt < 0)
    return false;
    if(i >= n)
    return (cnt == 0);

    if(dp[i][cnt] != -1)
    return dp[i][cnt];

    bool ans = false;
    if(s[i] == '(')
    ans = solve(i+1,cnt+1,n,s,dp);

    else if(s[i] == ')'){
        ans = solve(i+1, cnt-1,n,s,dp);
    }
    else{
        ans = solve(i+1,cnt,n,s,dp) || solve(i+1,cnt+1,n,s,dp) || solve(i+1,cnt-1,n,s,dp);
    }
    return dp[i][cnt] = ans;

}
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,0,n,s,dp);

    }
};