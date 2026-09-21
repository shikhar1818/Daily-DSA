// First Approach
class Solution {
public:
    static bool compare(const string &a , const string &b){
        return a.size() < b.size();
    }
    bool ispre(string s1, string s2){
        int n1 = s1.size();
        int n2 = s2.size();
        if(n2-n1 != 1)
        return false;

        int i = 0, j = 0;
        int cnt  = 0;
        while(i < n1 && j < n2){
            if(s1[i] != s2[j]){
                cnt++;
                if(cnt > 1)
                return false;
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),compare);
        vector<int> dp(n,1);
        int ans = 1;
        for(int i = 0; i < n; i++){
            int mx = 0;
            for(int j = 0; j < i; j++){
                if(ispre(words[j],words[i]))
                mx = max(mx,dp[j]);
            }
            dp[i] += mx;
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};