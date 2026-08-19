class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        vector<vector<int>> arr(n+1,vector<int>(11,0));
        for(int i = 0; i < reservedSeats.size(); i++){
            int r = reservedSeats[i][0];
            int c = reservedSeats[i][1];
            arr[r][c] = 1;
        }
        int res = 0;
        for(int i = 1; i <= n; i++){
            int a = 1,b = 1,c = 1;
            for(int j = 2; j <= 5; j++){
                if(arr[i][j] == 1){
                    a = 0;
                    break;
                }
            }
            for(int j = 4; j <= 7; j++){
                if(arr[i][j] == 1){
                    b = 0;
                    break;
                }
            }
            for(int j = 6; j <= 9; j++){
                if(arr[i][j] == 1){
                    c = 0;
                    break;
                }
            }
               if (a && c)
                res += 2;
            else if (a || b || c)
                res += 1;
        }
        return res;
    }
};