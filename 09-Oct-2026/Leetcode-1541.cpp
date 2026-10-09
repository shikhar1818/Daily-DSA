class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int score = 0;
        int cnt = 0;
        int i;
        for (i = 0; i < n - 1; i++) {
            if (s[i] == ')') {
                if (s[i + 1] == ')') {
                    if (score > 0)
                        score -= 2;
                    else
                    cnt++;
                    i++;
                } else {
                    if (score > 0) {
                        score -= 2;
                        cnt++;
                    } 
                    else
                    cnt += 2;
                }
            } 
            else
            score += 2;
        }
        if(i == n-1){
            if(s[i] == ')'){
                if(score > 0)
                score--;
                else
                cnt += 2;
            }
            else
            score += 2;
        }
        cnt += score;
        return cnt;
    }
};