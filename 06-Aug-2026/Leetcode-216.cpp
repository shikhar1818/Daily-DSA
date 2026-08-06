class Solution {
public:
    void fun(int k, int n, int sum, vector<vector<int>> &ans, vector<int> &arr, int last){
        if(k == 0){
            if(sum == n)
            ans.push_back(arr);
            return;
        }
        for(int i = last+1; i <= 9; i++){
            arr.push_back(i);
            fun(k-1,n,sum+i,ans,arr,i);
            arr.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> arr;
        fun(k,n,0,ans,arr,0);
        return ans;
        
    }
};