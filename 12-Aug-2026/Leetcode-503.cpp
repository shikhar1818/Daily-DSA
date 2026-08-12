class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;
        st.push(nums[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i])
                st.pop();
            st.push(nums[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < st.top())
                nge[i] = st.top();
            else {
                while (!st.empty() && st.top() <= nums[i])
                    st.pop();

                if (!st.empty())
                    nge[i] = st.top();
                else
                    nge[i] = -1;
            }
            st.push(nums[i]);
        }
        return nge;
    }
};