class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        bool zero = false;
        for(int i : nums){
            res = res^i;
            if(i)
            zero = true;
        }
        if(!zero)
        return 0;

        return res != 0 ? n : n-1;
    }
};