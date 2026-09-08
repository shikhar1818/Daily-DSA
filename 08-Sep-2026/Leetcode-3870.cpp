// First Brute force approach
class Solution {
public:
    int fun(int n){
        int dig = 0;
        while(n){
            dig++;
            n /= 10;
        }
        if(dig % 3 == 0)
        return (dig/3-1);

        return dig/3;
    }
    int countCommas(int n) {
        if(n < 1000)
        return 0;

        int ans = 0;
        for(int i = 1000; i <= n; i++){
            ans += fun(i);
        }
        return ans;
    }
};


// Second Optimised Approach
class Solution {
public:
    int fun(int n){
        int dig = 0;
        while(n){
            dig++;
            n /= 10;
        }
        if(dig % 3 == 0)
        return (dig/3-1);

        return dig/3;
    }
    int countCommas(int n) {
        if(n < 1000)
        return 0;

        int ans = 0;
        for(int i = 1000; i <= n; i *= 1000){
            int next = i*1000;
            if(n >= next)
            ans += (next-i)*fun(i);
            else
            ans += (n+1-i)*fun(i);
        }
        return ans;
    }
};