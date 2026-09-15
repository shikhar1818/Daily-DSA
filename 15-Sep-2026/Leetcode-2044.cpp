class Solution {
public:
int fun(vector<int>& nums, int i, int n,int ans, int x){
    if(i >= n)
    return 0;

    int cnt = 0;
    if((ans | nums[i]) == x)
    cnt++;

    cnt += fun(nums,i+1,n,(ans|nums[i]),x);
    cnt += fun(nums,i+1,n,ans,x);

    return cnt;

}
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for(int i = 0; i < n; i++)
        x = x | nums[i];

        return fun(nums,0,n,0,x);
    }
};