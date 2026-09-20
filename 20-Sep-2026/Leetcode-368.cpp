// First Approach
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n,1);
        int ans = 1;
        int k = 0;
        for(int i = 1; i < n; i++){
            int mx = 0;
            for(int j = 0; j < i; j++){
                if(!(nums[i]%nums[j]) || !(nums[j]%nums[i]))
                mx = max(mx,dp[j]);
            }
            dp[i] += mx;
            if(dp[i] > ans){
                ans = dp[i];
                k = i;
            }
        }
        vector<int> res(ans);                                     
        int j = ans-1;
        res[j--] = nums[k];
        ans--;
        while(ans){
          for(int i = 0; i < k; i++){
              if((!(nums[i]%nums[k]) || !(nums[k]%nums[i])) && dp[i] == ans){
                  res[j--] = nums[i];
                  k = i;
                  ans--;
                  break;
              }
          }  
        }
        return res;
    }
};



// Second Approach
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        sort(nums.begin(), nums.end());
        vector<int> dp(n,1);
        int ans = 1;
        int k = 0;
        for(int i = 0; i < n; i++){
            int prev = i;
            int mx = 0;
            for(int j = 0; j < i; j++){
                if((!(nums[i]%nums[j]) || !(nums[j]%nums[i])) && (dp[j] > mx)){
                   mx = dp[j];
                   prev = j; 
                }
            }
            dp[i] += mx;
            mp[i] = prev;
            if(dp[i] > ans){
                ans = dp[i];
                k = i;
            }
        }
        vector<int> res(ans); 
        int sz = ans-1;
        while(sz >= 0){
            res[sz--] = nums[k];
            k = mp[k];
        }
        return res;
    }
};