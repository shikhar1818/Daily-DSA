class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
        return 1;
        int mini = 0, maxi = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[mini])
            mini = i;
            if(nums[i] > nums[maxi])
            maxi = i;
        }
        int a = max(maxi,mini)+1;
        int b = n-min(maxi,mini);
        int c;
        if(maxi < mini)
        c = maxi+1+n-mini;
        else
        c = mini+1+n-maxi;

        return min(a,min(b,c)); 
    }
};