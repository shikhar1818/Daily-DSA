class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int l = 0, r = 0;
        int cnt = 0;
        string ans = "";
        int ms = INT_MAX;
        while(r < n){
            if(s[r] == '1'){
                cnt++;
                while(cnt > k){
                    if(s[l] == '1')
                    cnt--;
                    l++;
                }
                while(l <= r && s[l] == '0')
                l++;
            }
            if(cnt == k){
                int len = r-l+1;
                if(len <= ms){
                    string str = "";
                    for(int i = l;i <= r; i++){
                        str.push_back(s[i]);
                    }
                    if (len < ms || ans.empty() || (len == ms && str < ans)) {
                        ans = str;
                        ms = len;
                    ms = r-l+1;
                }
                }
            }
            r++;
        }
        return ans;
    }
};