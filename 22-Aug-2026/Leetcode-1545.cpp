class Solution {
public:
    string rev(string s){
        int n = s.size();
        string ans = "";
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '0')
            ans += '1';
            else
            ans += '0';
        }
        return ans;
    }

    string fun(int n){
        if(n == 1)
        return "0";

        string s1 = fun(n-1);
        string ans = s1 + '1' + rev(s1);
        return ans;
    }
    char findKthBit(int n, int k) {
        int a = 1;
        int dig = 0;
        for(int i = 1; i <= n; i++){
            dig += a;
            a *= 2;
        }

        string str = fun(n);

        int s = 0;
        int e = dig-1;
        char c;
        k = k-1;
        while(s <= e){
            int m = s + (e-s)/2;
            if(m == k){
                c = str[m];
                break;
            }
            else if(m > k)
            e = m-1;
            else
            s = m+1;
        }
        return c;

    }
};