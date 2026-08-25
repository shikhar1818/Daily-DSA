class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int l = 0,  r = 0;
        int ls = 0, rs = 0;
        for(int i = 0; i < n; i++){
            if(i < n/2){
                if(num[i] == '?')
                l++;
                else{
                    int ch = num[i]-'0';
                    ls += ch;
                }
            }
            else{
                if(num[i] == '?')
                r++;
                else{
                    int ch = num[i]-'0';
                    rs += ch;
                }  
            }
        }

        if(l == r)
        return ls != rs;

        if(abs(l-r) % 2 == 1)
            return true;

        if(2*(ls - rs) == 9*(r-l))
            return false;

        return true;
        
    }
};