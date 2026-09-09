class Solution {
public:
    long long fun(long long n){
        long long dig = 0;
        while(n){
            dig++;
            n /= 10;
        }
        if(dig % 3 == 0)
        return (dig/3-1);

        return dig/3;
    }
    long long countCommas(long long n) {

        if(n < 1000)
        return 0;
        
        long long ans = 0;
        for(long long i = 1000; i <= n; i *= 1000){
            long long next = i*1000;
            if(n >= next)
            ans += (next-i)*fun(i);
            else
            ans += (n+1-i)*fun(i);
        }
        return ans;
        
    }
};