class Solution {
public:
    int prod(int n){
        int ans = 1;
        while(n){
            ans *= (n%10);
            n /= 10;
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        int ans;
        int i = n;
        while(true){
            if(!(prod(i)%t)){
                ans =  i;
                break;
            }
            i++;
        }
        return ans;
    }
};