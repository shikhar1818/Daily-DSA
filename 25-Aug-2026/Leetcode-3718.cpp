class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i : nums){
            mp[i]++;
        }
        int cnt = k;
        while(mp[k])
        k += cnt;

        return k;
    }
};