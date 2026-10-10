class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
      int n = grid.size();
      vector<int> r(n);
      vector<int> c(n);

      for(int i = 0; i < n; i++){
        int mr = 0;
        int mc = 0;
        for(int j = 0; j < n; j++){
            mr = max(mr,grid[i][j]);
            mc = max(mc,grid[j][i]);
        }
        r[i] = mr;
        c[i] = mc;
      }
      int ans = 0;
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ans += min(r[i],c[j])-grid[i][j];
        }
      }
      return ans;
    }
};