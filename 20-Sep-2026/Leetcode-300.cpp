// First Approach
class Solution {
public:
    int fun(vector<int>& nums, int i, int j,int n, vector<vector<int>> &dp){
        if(j > n)
        return 0;

        if(dp[i][j] != -1)
        return dp[i][j];

        int t = 0, nt = 0;
        if(i == 0 || (nums[j-1] > nums[i-1]) )
        t = 1+fun(nums,j,j+1,n,dp);
        nt = fun(nums,i,j+1,n,dp);
        
        return dp[i][j] = max(t,nt);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return fun(nums,0,1,n,dp);
    }
};



// Second Approach
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+2,0));
        for(int i = n; i >= 0; i--){
            for(int j = n; j > i; j--){
                int t = 0,nt = 0;
                if(i == 0 || (nums[j-1] > nums[i-1]))
                t = 1+dp[j][j+1];
                nt = dp[i][j+1];
                dp[i][j] = max(t,nt);
            }
        }
        return dp[0][1];
    }
};


// Third Approach
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n,1);
        int ans = 1;
        for(int i = 1; i < n; i++){
            int mx = 0;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i])
                mx = max(mx,arr[j]);
            }
            arr[i] += mx;
            ans = max(ans,arr[i]);
        }
        return ans;
        
    }
};


// Fourth Approach
class Solution {
public:
    int fun(vector<int>& arr, int x,int n){
        int l = 0, r = n-1;
        int ans = n;
        while(l <= r){
            int m = l+(r-l)/2;
            if(arr[m] >= x){
                ans = m;
                r = m-1;
            }
            else
            l = m+1;
        }
        return ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        arr.push_back(nums[0]);
        int sz = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] > arr[sz-1]){
                arr.push_back(nums[i]);
                sz++;
            }
            else{
                arr[fun(arr,nums[i],sz)] = nums[i];
            }
        }
        return sz;
    }
};