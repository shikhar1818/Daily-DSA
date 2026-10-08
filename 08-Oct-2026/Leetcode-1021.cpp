class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        stack<char> st;
        string ans = "";
        for(int i = 0; i < n; i++){
            if(s[i] == '(')
            st.push('(');
            if(st.size() > 1)
            ans += s[i];
            if(s[i] == ')')
            st.pop();

        }
        return ans;
    }
};