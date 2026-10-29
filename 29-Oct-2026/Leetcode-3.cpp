class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char,bool> m;
       int l = 0;
       int ml = 0;
       int low = 0;
       int i = 0;
       while(i<s.length()){
        if(m.find(s[i]) == m.end() || m[s[i]] == false){
            l++;
            ml = max(l,ml);
            m[s[i]] = true;
            i++;
        }
        else if(m.find(s[i]) != m.end() || m[s[i]] == true){
            l--;
            m[s[low]] = false;
            low++;
        }
       } 
       return ml;
    }
};