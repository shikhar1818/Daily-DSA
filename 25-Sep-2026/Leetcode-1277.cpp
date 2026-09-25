class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> arr(m,vector<int>(n));
        int ans = 0;
        
        for(int i = 0; i < m; i++){
        arr[i][0] = matrix[i][0];
        ans += arr[i][0];
        }

        for(int i = 1; i < n; i++){
        arr[0][i] = matrix[0][i];
        ans += arr[0][i];
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 1)
                arr[i][j] = min(arr[i-1][j-1],min(arr[i-1][j],arr[i][j-1]))+1;
                else
                arr[i][j] = 0;

                ans += arr[i][j];
            }
        }
        return ans;
    }
};