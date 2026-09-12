#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int grid[MAXN][MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        if(k < n || k > 2*n - 1){
            cout << -1 << "\n";
            continue;
        }

        int m = 2*n - k; 

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                grid[i][j] = 0;

     
        for(int i = 1; i <= m; i++){
            grid[i][i] = i;
        }

        for(int row = m + 1; row <= n; row++){
            grid[row][1] = row;
        }

        for(int col = m + 1; col <= n; col++){
            grid[1][col] = n + (col - m);
        }

        int nextValue = k + 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(grid[i][j] == 0){
                    grid[i][j] = nextValue;
                    nextValue++;
                }
            }
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cout << grid[i][j];
                if(j < n) cout << ' ';
            }
            cout << "\n";
        }
    }

    return 0;
}