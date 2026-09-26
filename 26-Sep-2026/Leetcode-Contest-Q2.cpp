class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long s1 = 0, s2 = 0;
        for(int i : source)
            s1 += i;
        for(int i : target)
            s2 += i;

        return s1 == s2;
    }
};