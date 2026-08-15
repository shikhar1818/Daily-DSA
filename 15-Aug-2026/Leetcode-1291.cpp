class Solution {
public:
    int fun(int dig , int i){
        int exp = (int)pow(10,dig-1);
        int ans = 0;
        while(exp){
            ans += i*exp;
            exp /= 10;
            i++;
        }
        return ans;
    }
        int numdig(int n){
            int cnt = 0;
            while(n){
                cnt++;
                n /= 10;
            }
            return cnt;
        }
    vector<int> sequentialDigits(int low, int high) {
        int l = numdig(low);
        int h = numdig(high);
        vector<int> ans;
        while(l <= h){
            for(int j = 1; j <= 10-l; j++){
                int num = fun(l,j);
                if(num >= low && num <= high)
                ans.push_back(num);
                if(num > high)
                break;
            }
            l++;
        }
        return ans;
    }
};