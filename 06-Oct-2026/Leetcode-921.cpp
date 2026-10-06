class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int ans = 0;
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                ans++;
                st.push(ans);
            }
            else{
                if(st.empty())
                ans++;
                else{
                    ans = st.top()-1;
                    st.pop();
                }
            }
        }
        return ans;
    }
};