#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long x,y,k;
        cin >> x >> y >> k;
        long long ans = 0;
        long long d = y-x;
        long long le = x+k-1;
        long long a1 = min(d,le);
        for(long long a = x; a <= a1; a++){
            ans += d%a;
        }
        long long a2 = max(x,d+1);
        if(le >= a2){
            ans += (le-a2+1)*d;
        }
        cout << ans << endl;
    }
}