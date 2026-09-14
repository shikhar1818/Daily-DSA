#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> v1(N);
    for(int i = 0; i < N; i++)
    cin >> v1[i];

    int M;
    cin >> M;
    vector<int> v2(M);
    for(int i = 0; i < M; i++)
    cin >> v2[i];

    unordered_map<int,int> m1;
    unordered_map<int,int> m2;

    for(int i : v1)
    m1[i]++;

    for(int i : v2)
    m2[i]++;

    set<int> st;

    for(int i : v2){
        if(m2[i] > m1[i])
        st.insert(i);
    }

    vector<int> ans;

    for(int i : st)
    ans.push_back(i);

    int n = ans.size();
    if(n){
        for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
        cout << endl;
    }
    else
    cout << "-1" << endl;

    return 0;
}
