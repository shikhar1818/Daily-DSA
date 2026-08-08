class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int> arr(10,0);
        while(n){
            int r = n%10;
            arr[r]++;
            n /= 10;
        }
        int score = 0;
        for(int i = 1;i <= 9;i++){
            score += arr[i]*i;
        }
        return score;
    }
};