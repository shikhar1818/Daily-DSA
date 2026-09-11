// Using Bruteforce Approach

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_map<int,int> mp;
        int n = digits.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += digits[i]*100;
            for(int j = 0; j < n; j++){
                if(j == i)
                continue;
                ans += digits[j]*10;
                for(int k = 0; k < n; k++){
                    if(k == i || k == j)
                    continue;
                    ans += digits[k];
                    mp[ans]++;
                    ans -= digits[k];
                }
                ans -= digits[j]*10;
            }
            ans -= digits[i]*100;
        }
        int cnt = 0;
        for(int i = 100; i <= 999; i+=2){
            if(mp[i])
            cnt++;
        } 
        return cnt;
    }
};


// Little Optimised

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_map<int,int> mp;
        int n = digits.size();
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            ans += digits[i]*100;
            for(int j = 0; j < n; j++){
                if(j == i)
                continue;
                ans += digits[j]*10;
                for(int k = 0; k < n; k++){
                    if(k == i || k == j || digits[k]%2)
                    continue;
                    ans += digits[k];
                    mp[ans]++;
                    if((ans >= 100) && (ans <= 998) && (ans%2 == 0) && (mp[ans] == 1))
                    cnt++;
                    ans -= digits[k];
                }
                ans -= digits[j]*10;
            }
            ans -= digits[i]*100;
        }
        return cnt;
    }
};


// Best Approach

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_map<int,int> mp;
        int n = digits.size();
        int a = 0, b = 0, c = 0;
        for(int i = 0; i < n; i++){
            mp[digits[i]]++;
            if(mp[digits[i]] == 1)
            a++;
            else if(mp[digits[i]] == 2)
            b++;
            else if(mp[digits[i]] == 3)
            c++;
        }
        int ans = 0;
        for(int i = 0; i <= 8; i+=2){
            if(mp[i] >= 1){
                int aprime = a - (mp[i] == 1 ? 1 : 0);
                bool zeroAvail = mp[0] >= 1 && !(i == 0 && mp[0] == 1);

                if(aprime >= 2){
                    ans += aprime*(aprime-1);
                    if(zeroAvail)
                    ans -= (aprime-1);
                }
                if(b >= 1){
                    int d = b;
                    if(mp[0] >= 2)
                    d--;
                    if(i != 0){
                        if(mp[i] >= 2)
                        d--;
                        if(mp[i] >= 3)
                        d++;
                    }
                    ans += d;
                }
            }
        }
        return ans;
    }
};

