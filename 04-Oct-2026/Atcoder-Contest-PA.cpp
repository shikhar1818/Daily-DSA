#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    const ll INF = 4e18;
    while (t--) {
        int n;
        cin >> n;
        vector<int> x(n + 1), y(n + 1);
        vector<ll> z(n + 1), pref(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> x[i] >> y[i] >> z[i];
            pref[i] = pref[i - 1] + z[i];
        }
        vector<vector<ll>> best(500, vector<ll>(500, INF));
        for (int b = 0; b < 500; b++) {
            best[0][b] = 1LL * b * b;
        }
        ll answer = pref[n];
        for (int i = 1; i <= n; i++) {
            ll mn = INF;
            for (int a = 0; a < 500; a++) {
                ll dx = 1LL * x[i] - a;
                mn = min(mn, best[a][y[i]] + dx * dx);
            }
            ll dpi = pref[i - 1] + mn;
            answer = min(answer, dpi + pref[n] - pref[i]);
            ll base = dpi - pref[i];
            for (int b = 0; b < 500; b++) {
                ll dy = 1LL * b - y[i];
                best[x[i]][b] =
                    min(best[x[i]][b], base + dy * dy);
            }
        }
        cout << answer << endl;
    }
    return 0;
}