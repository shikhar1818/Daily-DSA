class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        unordered_map<int,int> mp;
        int ans = 0;
        int l = 0, r = 0;
        while(r < n){
            mp[s[r]-'a']++;
            while(mp[s[r]-'a'] > 2){
                mp[s[l]-'a']--;
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};