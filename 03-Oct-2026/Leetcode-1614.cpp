class Solution {
public:
    int maxDepth(string s) {
        int a = 0;
        int cnt = 0;
        for(char c : s){
            if(c == '(')
            a++;
            else if(c == ')')
            a--;
            cnt = max(cnt,a);
        }
        return cnt;
    }
};