#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n+1);
        for(int i = 1; i <= n; i++)
        cin >> arr[i];

        int i = 1,j = n;
        bool ans = true;
        while(i <= j){
            if(i == arr[i])
            i++;
            else if(j == arr[j])
            j--;
            else if(i == arr[j] &&  j == arr[i]){
                i++;
                j--;
            }
            else{
                ans = false;
                break;
            }
        }
        if(ans)
        cout << "YES" << endl;
        else
        cout << "NO" << endl;
    }
}