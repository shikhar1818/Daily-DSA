class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < k)
        return -1;
        if(n == k){
            int ans = -1;
            for(int i : nums)
            ans = max(ans,i);
            return ans;
        }
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        int ans = -1;
        if(k == 1){
            for(int i : nums){
                if(mp[i] == 1)
                ans = max(ans,i);
            }
            return ans;
        }
        if(mp[nums[0]] == 1 && mp[nums[n-1]] > 1)
        ans = nums[0];
        else if(mp[nums[0]] > 1 && mp[nums[n-1]] == 1)
        ans = nums[n-1];
        else if(mp[nums[0]] == 1 && mp[nums[n-1]] == 1)
        ans = nums[0] > nums[n-1] ? nums[0] : nums[n-1];
        else
        ans = -1;
        return ans;
    }
};