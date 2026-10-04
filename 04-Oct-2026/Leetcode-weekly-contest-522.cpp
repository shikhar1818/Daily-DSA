// ANS - 1
class Solution {
public:
    int minRotations(string s) {
        int n = s.size();
        int p = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int c = s[i]-'0';
            if(c == p)
            continue;
            else if(c > p)
            ans += min(c-p,10-c+p);
            else
            ans += min(p-c,10-p+c);
            p = c;
        }
        return ans;
    }
};



//  ANS - 2

class Solution {
public:
    int fun(int p,int c){
        int ans;
        if(c == p)
            ans = 0;
        else if(c > p)
            ans = min(c-p,10-c+p);
        else
            ans = min(p-c,10-p+c);
        return ans;
    }
    int minRotations(int n, string s) {
        int p = 0;
        int rs = 0;
        for(int i = 0; i < n; i++){
            int c = s[i]-'0';
            rs += fun(p,c);
            p = c;
        }
        int ls = 0;
        int g;
        p = s[n-1]-'0';
        int ans = INT_MAX;
        for(int i = n-1;i >= 1; i--){
            rs -= fun(s[i-1]-'0',s[i]-'0');
            g = fun(s[i-1]-'0',s[n-1]-'0');
            ls += fun(p,s[i]-'0');
            p = s[i]-'0';
            ans = min(ans,(rs+g+ls));
        }
        rs -= fun(0,s[0]-'0');
        g = fun(0,s[n-1]-'0');
        ls += fun(p,s[0]-'0');
        ans = min(ans,(rs+g+ls));
        return ans;
    }
};



//  ANS - 3

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        auto talveronix = nums;
        
        int n = nums.size();
        long long INF = 1e16;
        
        long long end_even_0 = -INF;
        long long end_odd_0 = -INF;
        long long end_even_1 = -INF;
        long long end_odd_1 = -INF;
        long long del_even_0 = -INF;
        long long del_odd_0 = -INF;
        
        long long max_ans = -INF;
        
        for (int x : talveronix) {
            long long next_end_even_0 = max((long long)x, end_odd_0 + x);
            long long next_end_odd_0 = end_even_0 - x;
            
            long long next_end_even_1 = max(end_odd_1 + x, del_odd_0 + x);
            long long next_end_odd_1 = max(end_even_1 - x, del_even_0 - x);
            
            long long next_del_even_0 = end_even_0;
            long long next_del_odd_0 = end_odd_0;
            
            end_even_0 = next_end_even_0;
            end_odd_0 = next_end_odd_0;
            end_even_1 = next_end_even_1;
            end_odd_1 = next_end_odd_1;
            del_even_0 = next_del_even_0;
            del_odd_0 = next_del_odd_0;
            
            max_ans = max({max_ans, end_even_0, end_odd_0, end_even_1, end_odd_1});
        }
        
        return max_ans; 
    }
};
