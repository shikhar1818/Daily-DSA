class Solution {
public:
    int digsum(int n){
        int sum = 0;
        while(n){
            sum += (n%10);
            n /= 10;
        }
        return sum;
    }
    int digpro(int n){
        int pro = 1;
        while(n){
            pro *= (n%10);
            n /= 10;
        }
        return pro;
    }
    bool checkDivisibility(int n) {
        int res = digsum(n)+digpro(n);
        if(n%res == 0)
        return true;

        return false;
        
    }
};