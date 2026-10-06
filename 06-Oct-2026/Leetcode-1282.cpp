class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        unordered_map<int,vector<int>> mp;
        for(int i = 0; i < n; i++){
            mp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for(int i = 1; i <= n; i++){
            int cnt = mp[i].size()/i;
            int k = 0;
            for(int j = 0; j < cnt; j++){
                vector<int> arr(i);
                for(int m = 0; m < i; m++)
                arr[m] = mp[i][k++];
                ans.push_back(arr);
            }
        }
        return ans;
    }
};