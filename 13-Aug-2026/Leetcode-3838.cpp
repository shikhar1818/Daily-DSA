class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        string ans = "";
        for(int i = 0; i < n; i++){
            int m = words[i].length();
            int wt = 0;
            for(int j = 0; j < m; j++){
                wt += weights[words[i][j]-'a'];
            }
            wt %= 26;
            char c = 122-wt;
            ans += c;
        }
        return ans;
    }
};