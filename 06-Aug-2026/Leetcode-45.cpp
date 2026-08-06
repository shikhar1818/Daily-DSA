class Solution {
public:
    int solve(vector<int>& nums,int idx,int n,vector<int> &dp){
        if(idx >= n){
            return 0;
        }
        if(dp[idx] != -1)
        return dp[idx];

        int ans = 1e9;

        for(int i = 1; i <= nums[idx];i++){
            ans = min(ans,1+solve(nums,idx+i,n,dp));
        }
        return dp[idx] = ans;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
        return 0;
        vector<int> dp(n,-1);
        return solve(nums,0,n-1,dp);
        
    }
};



