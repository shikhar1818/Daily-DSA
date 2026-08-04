class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i = y; i < y+k ; i++){
            int m = x+k-1;
            for(int j = x; j < x+k/2; j++){
                swap(grid[j][i],grid[m-(j-x)][i]);
            }
        }
        return grid;
        
    }
};