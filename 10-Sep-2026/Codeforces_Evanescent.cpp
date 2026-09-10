#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int r = 1;
        int ans = 1;
        int dec = 0;
        while(r < n-1){
            if(s[r] != s[r-1]){
                ans++;
                if(s[r] != s[r+1]){
                    dec = max(dec,1);
                    if(s[r-1] == s[r+1])
                    dec = max(dec,2);
                }

            }
            r++;
        }
        if(s[n-1] != s[n-2])
        ans++;

        ans -= dec;
        cout << ans << endl;

    }
}
