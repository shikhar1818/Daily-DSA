class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
        return 0;
        int l = 0, r = 1;
        int ans = 0;
        while(r < n-1){
            if(nums[r]-nums[r-1] != nums[r+1]-nums[r]){
                int len = r-l-1;
                ans += ((len)*(len+1))/2;
                l = r;
            }
            r++;
        }
        int len = r-l-1;
        ans += ((len)*(len+1))/2;
        return ans;
    }
};