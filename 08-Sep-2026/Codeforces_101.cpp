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
        int l = -1;
        bool f = false;
        for(int i = 0; i < n; i++){
            if(arr[i] == 1){
                if(!f)
                f = true;
                else{
                if(l != -1)
                arr[l] = 0;
                }
            }
            else if(arr[i] == -1){
                if(!f){
                    arr[i] = 1;
                    f = true;
                }
                else{
                    if(l != -1)
                    arr[l] = 0 ;

                    l = i;
                    arr[l] = 1;
                }
            }
        }

        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}