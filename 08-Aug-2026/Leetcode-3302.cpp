class Solution {
public:

    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> dp(n+1,0);
        int i = n-1,j = m-1;
        for(; i >= 0; i--){
            if(j >= 0 && word1[i] == word2[j]){
                dp[i] = dp[i+1] + 1;
                j--;
            }
            else
            dp[i] = dp[i+1];
        }
        vector<int> ans;
        bool flag = true;
        i = 0;
        j = 0;
        for(; i < n && j < m;i++){
            if(word1[i] == word2[j]){
                ans.push_back(i);
                j++;
            }
            else{
                if(flag){
                    if(dp[i+1] >= m-j-1){
                        ans.push_back(i);
                        j++;
                        flag = false;
                    }
                }

            }
        }
        if(j == m)
        return ans;

        return {};
        
    }
};