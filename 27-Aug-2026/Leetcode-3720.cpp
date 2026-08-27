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