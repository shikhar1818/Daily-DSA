#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        if (s[0] == '1') {
            cout << count(s.begin(), s.end(), '0') << "\n";
            continue;
        }

        int p = s.find('1');         
        if (p == (int)string::npos) { 
            cout << 0 << "\n";
            continue;
        }

        vector<int> suf0(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
            suf0[i] = suf0[i + 1] + (s[i] == '0');

        int ans = INT_MAX;
        int ones = 0; 
        for (int j = 0; j <= n; j++) {
            if (j >= p) ans = min(ans, ones + suf0[j]);
            if (j < n && s[j] == '1') ones++;
        }
        cout << ans << "\n";
    }
    return 0;
}