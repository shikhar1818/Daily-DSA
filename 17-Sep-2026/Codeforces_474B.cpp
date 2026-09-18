#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    cin >> a[i];

    int m;
    cin >> m;
    vector<int> b(m);
    for(int i = 0; i < m; i++)
    cin >> b[i];

    for(int i = 1; i < n; i++)
    a[i] += a[i-1];

    for(int i = 0; i < m; i++){
        int x = b[i];
        int ans = -1;
        int l = 0, r = n-1;
        while(l < r){
            int m = l+(r-l)/2;
            if(a[m] == x){
                ans = m+1;
                break;
            }
            else if(a[m] < x)
            l = m+1;
            else
            r = m;
        }
        if(ans == -1)
        ans = l+1;

        cout << ans << endl;
    }
    return 0;
}