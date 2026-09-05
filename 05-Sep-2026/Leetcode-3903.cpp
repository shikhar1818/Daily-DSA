class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> l(n);
        int mini = INT_MAX;
        for(int i = n-1; i >= 0; i--){
            if(nums[i] < mini)
            mini = nums[i];
            l[i] = mini;
        }
        int maxi = INT_MIN;
        int ans = -1;
        for(int i = 0;i < n; i++){
            if(nums[i] > maxi)
            maxi = nums[i];
            if(maxi-l[i] <= k){
                ans = i;
                break;
            }
        }
        return ans;   
    }
};