class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for (int i : nums)
            mp[i]++;
        vector<int> arr;
        for (int i = 0; i < nums[n - 1]; i++) {
            if (mp[i] == 0)
                arr.push_back(i);
        }
        int i = 0, ans = 0, j = 0;
        int m = arr.size();
        bool cross = false;
        int next;
        while (i < n) {
            if (mp[nums[i]] > 1) {
                if (!cross) {
                    while (j < m && arr[j] < nums[i])
                        j++;
                    if (j < m) {
                        next = arr[j];
                        j++;
                    } else {
                        next = nums[n - 1] + 1;
                        cross = true;
                    }
                } else
                    next += 1;

                ans += next - nums[i];
                mp[next]++;
                mp[nums[i]]--;
            } else
                i++;
        }

        return ans;
    }
};





class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int p = nums[0];
        int ans = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] > p)
            p = nums[i];
            else{
                ans += p+1-nums[i];
                p += 1;
            }
        }
        return ans;
    }
};