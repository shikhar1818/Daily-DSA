//  Simple DP approach
class Solution {
public:
    int fun(vector<int> &nums,int i, int j, int k,vector<vector<vector<int>>> &dp){
        if(k == 0)
        return 0;

        if(k < 0 || i > j)
        return 1e9;

        if(dp[i][j][k] != -1)
        return dp[i][j][k];

        return dp[i][j][k] = 1+min(fun(nums,i+1,j,k-nums[i],dp),fun(nums,i,j-1,k-nums[j],dp));
    }
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(x+1,-1)));
        int ans = fun(nums,0,n-1,x,dp);
        if(ans >= 1e9)
        return -1;
        else
        return ans;
        
    }
};




class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        unordered_map<int,int> mp;

        int total = 0;
        for(int i : nums)
        total += i;

        int target = total-x;
        total = 0;
        int len = -1;
        int l = 0,r = 0;
        while( r < n){
            total += nums[r];
            while(total > target && l <= r){
                total -= nums[l];
                l++;
            }

            if(total == target){
                len = max(len,r-l+1);
            }
            r++;
        }
        if(len == -1)
        return -1;

        return n-len;
    }
};