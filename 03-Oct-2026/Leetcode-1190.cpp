class Solution {
public:
    string reverseParentheses(string s) {
        vector<string> st;
        string cur = "";

        for(char c : s) {
            if(c == '(') {
                st.push_back(cur);
                cur = "";
            }
            else if(c == ')') {
                reverse(cur.begin(), cur.end());
                cur = st.back() + cur;
                st.pop_back();
            }
            else {
                cur += c;
            }
        }

        return cur;
    }
};