class Solution {
public:
    int fun(int n){
        int s = 0;
        while(n){
            s += (n%10);
            n /= 10;
        }
        return s;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(fun(nums[i]) == i)
            return i;
        }
        return -1;
    }
};