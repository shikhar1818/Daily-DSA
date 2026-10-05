class Solution {
public:
    int scoreOfParentheses(string s) {
      int n = s.size();
      stack<int> st;
      int score = 0;
      for(int i = 0; i < n; i++){
        if(s[i] == '('){
            st.push(score);
            score = 0;
        }
        else{
            if(s[i-1] == '(')
            score = st.top()+1;
            else
            score = st.top()+2*score;
            st.pop();
        }
      }  
      return score;
    }
};


class Solution {
public:
    int scoreOfParentheses(string s) {
      int n = s.size();
      int d = 0;
      int score = 0;
      for(int i = 0; i < n; i++){
        if(s[i] == '(')
        d++;
        else{
            d--;
            if(s[i-1] == '(')
            score += (1 << d);
        }
      }  
      return score;
    }
};