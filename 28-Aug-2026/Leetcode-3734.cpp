class Solution {
public:
    bool solve(vector<int>& arr, string& ans, string& target, int idx,
               char &mid, int n,bool isgreater) {
        if (idx == n){
            string temp = ans;

            if (mid != '*')
            temp.push_back(mid);

            string rev = ans;
            reverse(rev.begin(), rev.end());

            temp += rev;

            if(temp > target){
                return true;
            }
            return false;
        }

        for (int i = 0; i < 26; i++) {
            if(arr[i] == 0)
            continue;

            char c = (char)('a'+i);
            if(!isgreater && c < target[idx])
            continue;

            ans.push_back(c);
            bool gt = false;
            if(isgreater || c > target[idx])
            gt = true;

            arr[c-'a']--;

            if(solve(arr,ans,target,idx+1,mid,n,gt))
            return true;
            else
            ans.pop_back();
            arr[c-'a']++;
        }
        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> arr(26,0);
        for(int i = 0; i < n; i++)
        arr[s[i]-'a']++;

        int cnt = 0;
        char mid = '*';
        for(int i = 0; i < 26; i++){
            if(cnt > 1)
            break;

            if(arr[i]%2){
                cnt++;
                mid = (char)('a'+i);
            }
            arr[i] /= 2;
        }
        if(cnt > 1)
        return "";

        string ans = "";

        bool a = solve(arr,ans,target,0,mid,n/2,false);
        string res = ans;
        if(mid != '*')
        ans.push_back(mid);

        reverse(res.begin(),res.end());
        ans = ans+ res;

        if(a)
        return ans;

        if(ans > target && ans.size() == n)
        return ans;

        return "";

    }
};