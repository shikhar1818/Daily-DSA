class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_map<int,int> mp;
        mp[nums2[n2-1]] = n2-1;
        vector<int> nge(n2,-1);
        stack<int> st;
        st.push(nums2[n2-1]);
        for(int i = n2-2; i >= 0; i--){
            mp[nums2[i]] = i;
            if(nums2[i] < st.top())
                nge[i] = st.top();
            else{
                while(!st.empty() && st.top() <= nums2[i])
                st.pop();

                if(!st.empty())
                nge[i] = st.top();
                else
                nge[i] = -1;
            }
            st.push(nums2[i]);
        }
        vector<int> ans(n1);
        for(int i = 0; i < n1; i++){
            int ind = mp[nums1[i]];
            ans[i] = nge[ind];
        }
        return ans;
    }
};