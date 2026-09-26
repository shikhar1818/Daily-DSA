class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        int m = knowledge.size();
        unordered_map<string,string> mp;
        for(int i = 0; i < m; i++){
            mp[knowledge[i][0]] = knowledge[i][1];
        }
        int a = 0;
        string str = "";
        string ans = "";
        for(int i = 0; i < n; i++){
            if(a){
                if(s[i] == ')'){
                    if(mp.find(str) != mp.end())
                    ans += mp[str];
                    else
                    ans += '?';
                    str = "";
                    a = 0;
                }
                else
                str += s[i];
            }
            else{
                if(s[i] == '(')
                a = 1;
                else
                ans += s[i];
            }
        }
        return ans;
    }
};