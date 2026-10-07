// A
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int x0,y0,r;
        cin >> x0 >> y0 >> r;
        int x = x0;
        int y = y0-r;
        cout << x << " " << y << endl;
    }
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
        int n;
        cin >> n;
        string s;
        cin >> s;
        stack<int> st;
        vector<int> arr;
        for(int i  = 0; i < n; i++){
            if(s[i] == '1')
            st.push(i+1);
            else if(s[i] == '2'){
                if(!st.empty()){
                    st.pop();
                    arr.push_back(i+1);
                }
            }
        }
        while(!st.empty()){
            arr.push_back(st.top());
            st.pop();
        }
        sort(arr.begin(),arr.end());
        cout << arr.size() << "\n";
        for(int i : arr)
        cout << i << " ";
        cout << "\n";
    }
    return 0;
}



// C
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int m = n - 4;
        vector<long long> val(m);
        for (int i = 0; i < m; i++) {
            val[i] = a[i] + a[i + 2] - a[i + 4];
        }
        unordered_map<long long, long long> freq;
        long long ans = 0;
        for (int i = 0; i < m; i++) {
            ans += freq[val[i]];
            if (i - 2 >= 0 && val[i] == val[i - 2]) {
                ans--;
            }
            if (i - 4 >= 0 && val[i] == val[i - 4]) {
                ans--;
            }
            freq[val[i]]++;
        }
        cout << ans << '\n';
    }
    return 0;
}