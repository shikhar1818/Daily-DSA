// 1
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string p;
        cin >> p;
        string q;
        cin >> q;
        vector<int> m1(26,0);
        vector<int> m2(26,0);
        for(char c : p){
            m1[c-'a']++;
        }
 
        for(char c : q){
            if(m1[c-'a'])
            m1[c-'a']--;
            else
            m2[c-'a']++;
        }
        bool ans = true;
        for(int i = 0; i < 26; i++){
            char c = 'a'+i;
            if(m2[i] > 0 || m1[i] > 1 || (m1[i] >= 1 && c != 's' && c != 'i' && c != 'x')){
                ans = false;
                break;
            }
            if((c == 's' || c == 'i' || c == 'x') && (m1[i] != 1)){
                ans = false;
                break;
            }
        }
        if(ans)
        cout << "YES\n";
        else
        cout << "NO\n";
    }


// 2
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int x,y,z;
        cin >> x >> y >> z;
        string ans = "";
        char c;
        if(x >= y && x >= z)
        c = 'P';
        else if(y >= x && y >= z)
        c = 'R';
        else
        c = 'S';
        int cnt = x+y+z;
        for(int i = 0; i < cnt; i++)
        ans += c;
 
        cout << ans << "\n";
    }
}



//3
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
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
        cin >> arr[i];
        bool a = false, b = false;
        long long s = 0;
        for(int i = 0; i < n; i++){
            s += arr[i];
            if(arr[i] > 1){
                a = true;
                if(i > 0 && i < n-1)
                b = true;
            }
        }
        if(!a)
        cout << "-1\n";
        else if(b)
        cout << s-1 << "\n";
        else
        cout << s-n+1 << "\n";
    }
}



// 4
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
        vector<long long> arr(n);
        for(int i = 0; i < n; i++)
        cin >> arr[i];
        sort(arr.begin(),arr.end());
        long long med = arr[n/2];
        long long cost = 0;
        for(long long i : arr)
        cost += llabs(i-med);
        long long opr = arr[n-1]-arr[0];
 
        cout << cost << " " << opr << "\n";
        
    }
}


// 5
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
        vector<long long> c(n);
        long long total = 0;
        for(int i = 0; i < n; i++){
            long long x;
            cin >> x;
            c[i] = ((i + 1) % 2 == 0) ? x : -x;
            total += c[i];
        }
        sort(c.begin(), c.end(), greater<long long>());
        long long top = 0;
        for(int i = 0; i < n / 2; i++) top += c[i];
        cout << 2 * top - total << "\n";
    }
}