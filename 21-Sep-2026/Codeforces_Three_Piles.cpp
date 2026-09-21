#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long a,b,c;
        cin >> a >> b >> c;
        if(a >= b || (c > 2*(b-a) ))
        a += c;
        cout << abs(a-b) << endl;
    }
}