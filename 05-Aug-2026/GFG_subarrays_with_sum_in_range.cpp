class Solution {
  public:
  int maxsum(vector<int> &arr, int lim){
      int n = arr.size();
      int i = 0;
      int j = 0;
      int sum = 0;
      int cnt = 0;
      while(i <= j && j < n){
          sum += arr[j];
          while(sum > lim && i <= j){
              sum -= arr[i];
              i++;
          }
          cnt += j-i+1;
          j++;
      }
      return cnt;
  }
    int countSubarray(vector<int>& arr, int l, int r) {
        // code here
        return maxsum(arr,r)-maxsum(arr,l-1);
        
    }
};