#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        string s;
        cin >> n >> k;
        cin >> s;

        int cnt = 0;
        for(int i = 0; i < n; i += k){
            bool a = false;
            for(int j = i ; j < i+k; j++){
                if(s[j] == '0'){
                    a = true;
                    break;
                }
            }
            if(!a)
            cnt++;
        }

        cout << cnt << endl;

    }
}