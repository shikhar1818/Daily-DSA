class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.length();
        int cols = n/rows;

        string ans = "";
        for(int i = 0; i < cols; i++){
            int j = i;
            j = i;
            while(j < n){
                ans += encodedText[j];
                j += cols+1;
            }
        }

        while(!ans.empty() && ans.back() == ' ')
        ans.pop_back();
        
        return ans;
        
    }
};