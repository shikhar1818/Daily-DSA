class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        vector<int> lis(n,1);
        int max_lis = 1;
        for(int i = 0; i < n; i++){
            int max_el = 0;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i] && lis[j] > max_el)
                max_el = lis[j];
            }
            lis[i] += max_el;
            max_lis = max(max_lis,lis[i]);
        }
        
        if(max_lis == 1)
        return 0;
        
        vector<int> lds(n,1);
        int max_lds = 1;
        for(int i = n-1; i >= 0; i--){
            int max_el = 0;
            for(int j = n-1; j > i; j--){
                if(nums[j] < nums[i] && lds[j] > max_el)
                max_el = lds[j];
            }
            lds[i] += max_el;
            max_lds = max(max_lds,lds[i]);
        }
        
        if(max_lds == 1)
        return 0;
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            if(lis[i] > 1 && lds[i] > 1)
            ans = max(ans,lis[i]+lds[i]-1);
        }
        return ans;
    }
};
