class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        int k = k1+k2;
        int maxd = 0;
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            mp[abs(nums1[i]-nums2[i])]++;
            maxd = max(maxd,abs(nums1[i]-nums2[i]));
        }
        for(int i = maxd; i >= 0 && k > 0; i--){
            int cnt = min(mp[i],k);
            mp[i] -= cnt;
            mp[i-1] += cnt;
            k -= cnt;
        }
        long long ans = 0;
        for(int i = maxd; i > 0; i--){
            ans += 1LL*i*i*mp[i];
        }
        return ans;
    }
};