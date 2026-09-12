#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
        cin >> arr[i];

        int a = 0, b = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == 1)
            a++;
            else
            b++;
        }
        if(a >= b)
        cout << "Bessie" << endl;
        else
        cout << "Elsie" << endl;
    }
}