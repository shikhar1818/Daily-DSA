class Solution {
public:
    string solve(int n){
        if(n == 1)
        return "1";

        string s = solve(n-1);
        int m = s.size();
        string ans = "";
        int cnt = 1;
        int i = 0;
        for(i = 0; i < m-1 ; i++){
            if(s[i] != s[i+1]){
                ans.push_back((cnt+'0'));
                ans.push_back(s[i]);
                cnt = 1;
            }
            else
            cnt++;
        }
        ans.push_back((cnt+'0'));
        ans.push_back(s[i]);
        return ans;

    }
    string countAndSay(int n) {
        return solve(n);
    }
};