#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<long long> arr(N);
    for(int i = 0; i < N; i++)
    cin >> arr[i];

    long long mini = INT_MAX;
    long long maxi = INT_MIN;

    for(long long i : arr){
        mini = min(mini,i);
        maxi = max(maxi,i);
    }

    double x = (mini / 2.0) + (maxi / 2.0);
    double diff = 1e18;
    long long ans;

    for(int i = 0; i < N; i++){
        if(abs(x-arr[i]) < diff){
            diff = abs(x-arr[i]);
            ans = arr[i];
        }
        else if(abs(x-arr[i]) == diff && arr[i] < ans)
        ans = arr[i];
    }

    cout << ans << endl;
    
}
