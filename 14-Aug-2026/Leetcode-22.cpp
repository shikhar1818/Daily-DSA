class Solution {
public:
    void fun(int n, int m, vector<string> &ans,string &s){
        if(m < n)
        return;

        if(!n && !m)
        ans.push_back(s);

        if(n){
            s.push_back('(');
            fun(n-1,m,ans,s);
            s.pop_back();

        }
        if(m){
            s.push_back(')');
            fun(n,m-1,ans,s);
            s.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        vector<string> ans;
        fun(n,n,ans,s);
        return ans;
    }
};