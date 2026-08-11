class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i : nums)
            mp[i]++;

        int ans = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1)
                ans += nums[i];
            else
                break;
        }
        while (mp[ans])
            ans++;

        return ans;
    }
};