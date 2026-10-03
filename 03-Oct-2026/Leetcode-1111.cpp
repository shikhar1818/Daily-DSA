class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
       int n = seq.size();
       vector<int> ans(n);
       int a = 0, b = 0;
       for(int i = 0;i < n; i++){
        if(seq[i] == '('){
            if(a < b){
                ans[i] = 0;
                a++;
            }
            else{
                ans[i] = 1;
                b++;
            }
        }
        else{
            if(b >= a){
                ans[i] = 1;
                b--;
            }
            else{
                ans[i] = 0;
                a--;
            }
        }
       }
       return ans;
    }
};