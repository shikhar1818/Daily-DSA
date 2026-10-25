class Solution {
public:
    int sumCounts(vector<int>& nums) {
       int n = nums.size();
       int s = 0;
       for(int i = 0; i < n; i++){
        int cnt = 0;
        vector<int> arr(101,0);
        for(int j = i; j < n; j++){
            if(arr[nums[j]] == 0)
            cnt++;
            arr[nums[j]] = 1;
            s += cnt*cnt;
        }
       } 
       return s;
    }
};