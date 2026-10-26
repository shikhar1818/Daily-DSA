// Q-1
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
        cin >> arr[i];
 
        vector<int> mp(n);
        for(int i = 0; i < n; i++)
        mp[arr[i]] = i;
 
        vector<bool> vis(n,false);
 
        int last = 0,s = -1, e = -1;
        int mxi = 0;                        
        for(int i = 0; i <= n-k; i++){
            vis[arr[i]] = true;
            if(arr[i] > arr[mxi]) mxi = i;  
            while(last < n && vis[last])    
            last++;
            if(last <= i){
                s = mxi;                     
                e = mp[last];
            }
            else{
                s = -1;
                e = -1;
            }
        }
        if(s == -1 && e == -1)
        cout << "-1\n";
        else
        cout << s+1 << " " << e+1 << "\n";
 
    }
    return 0;
}


// Q-2
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string a, b;
        cin >> n >> a >> b;
        int single = 0;
        for (int i = 0; i < n; i++)
            if (a[i] != b[i]) single++; 
        cout << single % 2 << "\n";
    }
    return 0;
}


// Q-3
#include <bits/stdc++.h>
using namespace std;
 
int n, x;
vector<long long> a;
 
bool ok(long long k) {
    int cost = 0;
    auto iso = [&](int i) {
        if (i > 0 && a[i] - a[i-1] <= k) return false;
        if (i < n-1 && a[i+1] - a[i] <= k) return false;
        return true;
    };
    for (int i = 0; i < n; i++) {
        if (!iso(i)) continue;
        cost++;
        if (i + 1 < n && iso(i+1) && a[i+1] - a[i] <= 2*k) i++; 
        if (cost > x) return false;
    }
    return cost <= x;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        a.assign(n, 0);
        for (auto &v : a) cin >> v;
        long long lo = 1, hi = 1e9;
        while (lo < hi) {
            long long mid = (lo + hi) / 2;
            if (ok(mid)) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << "\n";
    }
    return 0;
}



// Q-4
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        vector<int> c(k + 1, 0), sz(k + 1, 0);
        int big = -1;
        for (int i = 1; i <= k; i++) {
            int n;
            cin >> n;
            sz[i] = n;
            vector<int> deg(n + 1, 0), xr(n + 1, 0);
            for (int j = 0; j < n - 1; j++) {
                int u, v;
                cin >> u >> v;
                deg[u]++; deg[v]++;
                xr[u] ^= v; xr[v] ^= u;
            }
            if (n >= 2) {
                for (int v = 1; v <= n; v++)
                    if (deg[v] == 1) { c[i] = xr[v]; break; }
                if (big == -1) big = i;
            }
        }
        if (big == -1) {
            for (int i = 2; i <= k; i++)
                cout << i << " 1 1 1\n";
        } else {
            for (int i = 1; i <= k; i++) {
                if (i == big) continue;
                int v = (sz[i] >= 2) ? c[i] : 1;
                cout << i << " " << v << " " << big << " " << c[big] << "\n";
            }
        }
    }
    return 0;
}


