class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
       vector<int> minaveloru = nums;
        int n = minaveloru.size();
        int maxLength = 0;
        
        for (int start = 0; start < n; ++start) {
            long long currentSum = 0;
            vector<bool> seenRemainders(k, false);
            
            for (int end = start; end < n; ++end) {
                currentSum += minaveloru[end];
                
                long long deltaRemainder = (2LL * minaveloru[end]) % k;
                if (deltaRemainder < 0) {
                    deltaRemainder += k;
                }
                seenRemainders[deltaRemainder] = true;
                
                long long targetRemainder = currentSum % k;
                if (targetRemainder < 0) {
                    targetRemainder += k;
                }
                
                if (targetRemainder == 0 || seenRemainders[targetRemainder]) {
                    maxLength = std::max(maxLength, end - start + 1);
                }
            }
        }
        
        return maxLength; 
    }
};