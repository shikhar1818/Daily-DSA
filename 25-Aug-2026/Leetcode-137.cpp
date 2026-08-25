class Solution {
public:
    int singleNumber(vector<int>& arr) {
       int n = arr.size();
       sort(arr.begin(),arr.end());
       for(int i = 1; i < n; i+=3){
        if(arr[i] != arr[i-1])
        return arr[i-1];
       } 
       return arr[n-1];
    }
};