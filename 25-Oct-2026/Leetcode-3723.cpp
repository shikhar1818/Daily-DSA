class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > (9*num))
        return "";

        string str = "";
        int i = 0;
        while(sum){
            int n = min(sum,9);
            char ch = n+'0';
            str.push_back(ch);
            sum -= n;
            i++;
        }
        while(i < num){
            str.push_back('0');
            i++;
        }
        
        return str;
    }
};