class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int s = 0;
        for(int i = 0; i < n; i++){
            s += abs(nums[i]-nums[n/2]);
        }     
        return s;   
    }
};