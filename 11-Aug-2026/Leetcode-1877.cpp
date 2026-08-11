class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int l = INT_MAX;
        int r = INT_MIN;
        for(int i = 0; i < n; i++){
            if(nums[i] < l)
            l = nums[i];
            if(nums[i] > r)
            r = nums[i];
            mp[nums[i]]++;
        }
        int ans = 0;
        while(l <= r){
            if(!mp[l])
            l++;
            else if(!mp[r])
            r--;
            else{
                ans = max(ans,l+r);
                mp[l]--;
                mp[r]--;
            }
        }
        return ans;
    }
};