#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        int a = 0;
        int b = 0;
        int c = 0;
        for(int i = 0; i < n; i++){
            if(arr[i]%2 == 1)
            a++;
            else if(arr[i]%4 == 0)
            b++;
            else
            c++;
        }

        int ans = max(a,max(b,c));
        cout << ans << endl;
    }
}