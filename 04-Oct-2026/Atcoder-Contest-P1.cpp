#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> ans(n);
    for(int i = 0; i < n; i++)
    ans[i] = (m/n);
    int k = m%n;
    for(int i = 0; i < k; i++)
    ans[i]++;
    for(int i : ans)
    cout << i << endl;
}