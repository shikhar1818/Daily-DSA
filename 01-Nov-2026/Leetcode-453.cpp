// 1st Approach
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int mn = nums[0];
        for(int i = 1; i < n; i++)
        mn = min(mn,nums[i]);

        int ans = 0;
        for(int i : nums)
        ans += (i-mn);
        return ans;
    }
};



// 2nd Approach
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int mn = nums[0];
        int s = 0;
        for(int i = 0; i < n; i++){
        mn = min(mn,nums[i]);
        s += nums[i];
        }
        return s-n*mn;
    }
};