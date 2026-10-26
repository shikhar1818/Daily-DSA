class Solution {
public:
    int fun(vector<vector<int>>& grid, int i, int j, int &m, int &n,int &k){
        if(i < 0 || i >= m || j < 0 || j >= n)
        return 0;
        if(grid[i][j] == 0 || grid[i][j] == -1)
        return 0;
        int t = grid[i][j];
        grid[i][j] = -1;
        int l = fun(grid,i,j-1,m,n,k);
        int u = fun(grid,i-1,j,m,n,k);
        int r = fun(grid,i,j+1,m,n,k);
        int d = fun(grid,i+1,j,m,n,k);

        return (t+l+u+r+d)%k;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] > 0 && !(fun(grid,i,j,m,n,k)%k))
                cnt++;
            }
        }
        return cnt;
        
    }
};