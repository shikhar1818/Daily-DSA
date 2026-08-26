class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)
        return 0;
        int cnt = n/2;
        vector<bool> prime(n,true);
        for (int i = 3; i*i < n; i += 2) {
            if (prime[i]) {
                int d = i*2;
                for (int j = i*i; j < n; j += d) {
                    if(prime[j]){
                    prime[j] = 0;
                    cnt--;
                    }
                }
            }
        }
        return cnt;
    }
};