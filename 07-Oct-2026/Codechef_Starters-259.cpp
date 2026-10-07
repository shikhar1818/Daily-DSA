// A
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,k,y;
    cin >> x >> k >> y;
    bool a = false;
    if(y >= k && y <= x*k && (y%k) == 0)
    cout << "YES";
    else
    cout << "NO";
    return 0;
}




// B
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        string s;
        cin >> s;
        string l;
        cin >> l;
        vector<int> mp(26,0);

        for(char c : l)
        mp[c-'a']++;

        int ans = 1;
        int cnt = 1;
        bool isleft;
        if(mp[s[0]-'a'])
        isleft = true;
        else
        isleft = false;
        for(int i = 1; i < n; i++){
            if(mp[s[i]-'a']){
                if(isleft){
                    cnt++;
                    ans = max(ans,cnt);
                }
                else{
                    cnt = 1;
                    isleft = true;
                }
            }
            else{
               if(!isleft){
                    cnt++;
                    ans = max(ans,cnt);
                }
                else{
                    cnt = 1;
                    isleft = false;
                } 
            }
        }
        cout << ans << endl;
    }
    return 0;
}




// C
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int x = 0, y = 0;
        int u = 0, d = 0, l = 0, r = 0;
        for(char c : s){
            if(c == 'U'){
                y += 1;
                u++;
            }
            else if(c == 'D'){
                 y -= 1;
                 d++;
            }
            else if(c == 'L'){
                 x -= 1;
                 l++;
            }
            else if(c == 'R'){
                 x += 1;
                 r++;
            }
        }
        bool a = false;
        if(x == 2 && y == 0 && r > 1)
        a = true;
        else if(x == -2 && y == 0 && l > 1)
        a = true;
        else if(x == 0 && y == 2 && u > 1)
        a = true;
        else if(x == 0 && y == -2 && d > 1)
        a = true;
        if(a)
        cout << "YES" << endl;
        else
        cout << "NO" << endl;
    }
    return 0;
}




// D
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string a, b;
        cin >> a >> b;

        int onesA = count(a.begin(), a.end(), '1');
        int onesB = count(b.begin(), b.end(), '1');

        if (onesA % 2 == onesB % 2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}




// E
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<vector<int>> adj(N + 1);
        vector<int> degree(N + 1, 0);

        for (int i = 0; i < N - 1; i++) {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);

            degree[u]++;
            degree[v]++;
        }

        long long total = 1LL * N * (N - 1) * (N - 2) / 6;

        int leaves = 0;

        vector<int> leafCnt(N + 1, 0);

        for (int v = 1; v <= N; v++) {
            if (degree[v] == 1) {
                leaves++;

                int parent = adj[v][0];
                leafCnt[parent]++;
            }
        }

        long long badLeaf = 1LL * leaves * (N - 2);

        for (int v = 1; v <= N; v++) {
            badLeaf -= 1LL * leafCnt[v] * (leafCnt[v] - 1) / 2;
        }

        long long extraBad = 0;

        for (int v = 1; v <= N; v++) {
            if (degree[v] == 2) {
                bool hasLeafNeighbor = false;

                for (int u : adj[v]) {
                    if (degree[u] == 1) {
                        hasLeafNeighbor = true;
                        break;
                    }
                }

                if (!hasLeafNeighbor) {
                    extraBad++;
                }
            }
        }

        long long answer = total - badLeaf - extraBad;

        cout << answer << '\n';
    }

    return 0;
}