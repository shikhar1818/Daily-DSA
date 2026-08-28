class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> arr(26, 0);
        for (char c : s) {
            arr[c - 'a']++;
        }
        string ans = "";
        int i = 0;
        while (i < n && arr[target[i] - 'a'] > 0) {
            ans.push_back(target[i]);
            arr[target[i] - 'a']--;
            i++;
        }
        for (int pos = i; pos >= 0; pos--) {
            if (pos < i) {
                arr[target[pos] - 'a']++;
            }
            if (pos == n) {
                continue;
            }
            int ch = target[pos] - 'a';
            for (int j = ch + 1; j < 26; j++) {
                if (arr[j] > 0) {
                    string temp = target.substr(0, pos);
                    temp.push_back('a' + j);
                    arr[j]--;
                    for (int k = 0; k < 26; k++) {
                        while (arr[k] > 0) {
                            temp.push_back('a' + k);
                            arr[k]--;
                        }
                    }
                    return temp;
                }
            }
        }
        return "";
    }
};



// Method 2
class Solution {
public:
    bool solve(vector<int> &arr,string &ans,string &target,int idx,bool isgreater,int n){
        if(idx == n)
        return isgreater;

        for(int i = 0; i < 26; i++){
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

            if(solve(arr,ans,target,idx+1,gt,n))
            return true;
            else
            ans.pop_back();
            arr[c-'a']++;
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> arr(26,0);
        for(int i = 0; i < n; i++)
        arr[s[i]-'a']++;

        string ans = "";
        if(solve(arr,ans,target,0,false,n))
        return ans;

        return "";
    }
};