class Solution {
  public:
    vector<int> getLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n,1);
        int ans = 1;
        int k = 0;
        for(int i = 1; i < n; i++){
            int mx = 0;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i])
                mx = max(mx,arr[j]);
            }
            arr[i] += mx;
            if(arr[i] > ans){
                ans = arr[i];
                k = i;
            }
        }
        vector<int> res(ans);
        int j = ans-1;
        res[j--] = nums[k];
        ans--;
        while(ans){
          for(int i = 0; i < k; i++){
              if(nums[i] < nums[k] && arr[i] == ans){
                  res[j--] = nums[i];
                  k = i;
                  ans--;
                  break;
              }
          }  
        }
        return res;
    }
};