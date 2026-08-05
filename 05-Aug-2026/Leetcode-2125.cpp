class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int a = 0, b = 0;
        int ans = 0;
        int i = 0;
        while (i < n ) {
            while(!a && i < n) {
                for (char c : bank[i]) {
                    if(c == '1')
                    a++;
                }
                i++;
            }
            while(!b && i < n) {
                for (char c : bank[i]) {
                    if(c == '1')
                    b++;
                }
                i++;
            }
            ans += a*b;
            a = b;
            b = 0;
        }
        return ans;
    }
};