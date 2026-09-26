class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int si = source[0];
        int sj = source[1];

        int ti = target[0];
        int tj = target[1];

        if(ti == si && tj == sj)
        return 0;
        else if((ti+tj) == (si+sj) || ti == si || tj == sj || (ti-tj == si-sj) || (tj-ti == sj-si))
        return 1;

        return 2;
    }
};©leetcode