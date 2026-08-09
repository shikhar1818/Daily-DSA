class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> arr1(n+1,0);
        vector<int> arr2(n+1,0);
        int cnt = 0;
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            arr1[A[i]]++;
            arr2[B[i]]++;
            if(A[i] != B[i]){
                if(arr1[A[i]] == arr2[A[i]])
                cnt++;
                if(arr1[B[i]] == arr2[B[i]])
                cnt++;
            }
            else{
                if(arr1[A[i]] == arr2[B[i]])
                cnt++;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};