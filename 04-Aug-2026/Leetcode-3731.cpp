class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int min = nums[0];
        int max = nums[0];
        for(int i : nums){
            if(i < min)
            min = i;
            if(i > max)
            max = i;
            mp[i]++;
        }
        vector<int> ans;
        for(int i = min; i <= max; i++){
            if(mp[i] == 0)
            ans.push_back(i);
        }
        return ans;
    }
};