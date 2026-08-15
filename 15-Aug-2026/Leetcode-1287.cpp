class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
       int n = arr.size();
       unordered_map<int,int> mp;
       for(int i : arr)
       mp[i]++;
       int ans;
       for(int i : arr){
        if(mp[i] > (n/4))
        ans = i;
       }
       return ans;
    }
};