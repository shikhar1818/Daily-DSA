#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i  = 0; i < n; i++)
    cin >> arr[i];

    unordered_map<int,int> mp;
    for(int i = 0; i < n; i++){
        if(i == k)
        continue;
        mp[arr[i]]++;
    }

    int d = n-1;
    for(int i = k+1; i < n; i++){
        if(arr[i] == 1)
        d--;
        mp[arr[i]]--;
        mp[arr[i]-1]++;
    }
    int t = arr[k]-1;
    int ans = n-k+1;
    int i = 1;
    while(t){
        ans += d+1;
        t--;
        d -= mp[i];
        i++;

    }
    cout << ans-1 << endl;
}