class Solution {
public:
    int hIndex(vector<int>& citations) {
       int n = citations.size();
       int max_el = INT_MIN;
       for(int i : citations)
       max_el = max(max_el,i);

       vector<int> arr(max_el+1,0);
       for(int i : citations)
       arr[i]++;

       if(arr[max_el] >= max_el)
       return max_el;

       int ans = 0;

       for(int i = max_el-1; i >= 0; i--){
        arr[i] += arr[i+1];
        if(arr[i] >= i){
            ans = i;
            break;
        }
       }
       return ans;
    }
};