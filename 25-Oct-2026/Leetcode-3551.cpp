class Solution {
public:
    static int sod(int n){
        int s = 0;
        while(n){
            s += n%10;
            n /= 10;
        }
        return s;
    }
    static bool compare(int a, int b){
        int s1 = sod(a);
        int s2 = sod(b);
        if(s1 == s2)
        return a < b;
        return s1 < s2;
    }
    int cycle(vector<int> &arr,int n){
        vector<bool> flag(n,true);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(flag[i]){
                cnt++;
                flag[i] = false;
                int j = arr[i];
                while(j != i){
                    flag[j] = false;
                    j = arr[j];
                }
            }
        }
        return cnt;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]] = i;
        } 
        sort(nums.begin(),nums.end(),compare);
        vector<int> arr(n);
        for(int i  = 0; i < n; i++){
            arr[i] = mp[nums[i]];
        }
        return n-cycle(arr,n);
    }
};