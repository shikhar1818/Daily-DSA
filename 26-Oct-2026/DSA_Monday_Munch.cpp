#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int x , y;
        cin >> x >> y;
        if((x == 0 && y == 0) || x != y)
        cout << "NO" << endl;
        else
        cout << "YES" << endl;
    }
}



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
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
        cin >> arr[i];

        if(n%2){
        cout << "-1\n";
        continue;
        }
        int cnt = 0;
        for(int i : arr){
            if(i == 1)
            cnt++;
        }
        cnt = abs(n-2*cnt);
        cout << cnt/2 << "\n";
    }
    return 0;
}



#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string A;
        cin >> A;
        
        long long s = 0;
        for (char digit : A) {
            s += (digit - '0');
        }
        
        if (s % 10 == 0) {
            cout << "Valid\n";
        } else {
            cout << "Invalid\n";
        }
    }
    return 0;
}






#include <bits/stdc++.h>
using namespace std;

int fun(int s){
    if(s < 0)
    return 0;
    if(s == 0)
    return 1;

    return fun(s-1)+fun(s-2);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s;
    cin >> s;
    cout << fun(s) << "\n";
    return 0;
}




#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c >= 'a' && c <= 'n') {
            ans.push_back('n' - (c - 'a'));
        }
        else if (c >= 'o' && c <= 'z') {
            ans.push_back('z' - (c - 'o'));
            if (i + 1 < s.size() && s[i + 1] == '#') {
                i++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}