#include <bits/stdc++.h>
using namespace std;
int solve(int i, int j, int n, vector<vector<int>> &arr,vector<vector<int>> &dp){
    if(i >= n || j > i)
    return 0;
    
    if(dp[i][j] != -1)
    return dp[i][j];
    
    int ans = 0;
    int a = solve(i+1,j,n,arr,dp);
    int b = solve(i+1,j+1,n,arr,dp);
    ans = arr[i][j]+max(a,b);
    return dp[i][j] = ans;
}

int main() {
	int t,n;
	cin >> t;
	while(t--){
	    cin >> n;
	    vector<vector<int>> arr(n,vector<int>(n));
	    vector<vector<int>> dp(n,vector<int>(n,-1));
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j <= i; j++){
	            cin >> arr[i][j];
	        }
	    }
	    cout << solve(0,0,n,arr,dp) << endl;
	    
	}

}
