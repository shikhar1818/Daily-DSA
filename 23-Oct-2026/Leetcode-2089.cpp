class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> arr(101,0);
        for(int i = 0; i < n; i++){
            arr[nums[i]]++;
        }
        int st = 0;
        for(int i = 1; i <= 100; i++){
            if(i == target)
            break;
            st += arr[i];
        }
        vector<int> ans;
        int end = st+arr[target]-1;
        for(int i = st; i <= end; i++)
        ans.push_back(i);

        return ans;
    }
};