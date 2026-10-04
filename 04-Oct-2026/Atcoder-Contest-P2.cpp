#include<bits/stdc++.h>
using namespace std;
int fun(int i,int cnt,int v,int n,vector<int> &arr,vector<vector<vector<int>>> &dp){
    if(cnt == 0 || v < 0 || i == n)
    return 0;

    int t = 0,nt = 0;
    if(v-i-1 >= 0)
    t = arr[i]+fun(i+1,cnt-1,v-i-1,n,arr,dp);

    nt = fun(i+1,cnt,v,n,arr,dp);

    return dp[i][cnt][v] = max(t,nt);
}
int main(){
    int n,v;
    cin >> n >> v;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    cin >> arr[i];
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(4,vector<int>(v+1)));
    cout << fun(0,3,v,n,arr,dp) << endl;
    return 0;
}