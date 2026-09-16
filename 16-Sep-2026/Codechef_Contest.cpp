// 1. Sharing Cookies
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int A,B;
	cin >> A >> B;
	int ans = -1;
	if((A-B)%2 == 0)
	ans = (A-B)/2;
	
	cout << ans << endl;

}


// 2. Bus Seating
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n,k;
	    cin >> n >> k;
	    int ans;
	    if(k <= n)
	    ans = 0;
	    else{
	        ans = (k-n)*2;
	    }
	    cout << ans << endl;
	}

}


// 3. Fixed Points
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n , k;
	    cin >> n >> k;
	    
	    if(k == n-1)
	    cout << "No" << endl;
	    else
	    cout << "Yes" << endl;
	}

}



// 4. Red and Blue Elements
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<long long> arr(n);

        for(int i = 0; i < n; i++)
            cin >> arr[i];

        sort(arr.rbegin(), arr.rend());

        long long total = 0;

        for(auto x : arr)
            total += x;

        long long sr = 0;
        long long ans = 0;

        for(int k = 1; k < n; k++) {

            sr += arr[k - 1];

            long long sb = total - sr;
            long long cb = n - k;

            long long value = sr * cb + sb * k;

            ans = max(ans, value);
        }

        cout << ans << '\n';
    }
}
