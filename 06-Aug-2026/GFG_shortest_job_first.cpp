class Solution {
  public:
    int solve(vector<int>& bt) {
        // code here
        int n = bt.size();
        sort(bt.begin(),bt.end());
        int wt = 0;
        int sum = 0;
        for(int i = 0; i < n-1; i++){
            wt += bt[i];
            sum += wt;
        }
        return (sum/n);
        
    }
};