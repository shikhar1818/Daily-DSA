class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<long long> row(m,0);
        vector<long long> col(n,0);
        long long ts = 0;
        for(int i = 0; i < m; i++){
            long long sum = 0;
            for(int j = 0; j < n; j++){
                sum += grid[i][j];
                col[j] += grid[i][j];
            }
            ts += sum;
            row[i] = sum;
        }
        long long rs = 0;
        for(int i = 0; i < m-1; i++){
            rs += row[i];
            if(rs == ts-rs)
            return true;
        }
        long long cs = 0;
        for(int i = 0; i < n-1; i++){
            cs += col[i];
            if(cs == ts-cs)
            return true;
        }
        return false;
    }
};