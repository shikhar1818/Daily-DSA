class Solution {
public:
    struct interval{
        int start;
        int finish;
    };
    static bool compare(interval a,interval b){
        if(a.finish == b.finish){
            return (a.start < b.start);
        }
        return (a.finish < b.finish);
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<interval> arr(n);
        for(int i = 0; i < n; i++){
            arr[i].start = intervals[i][0];
            arr[i].finish = intervals[i][1];
        }
        sort(arr.begin(),arr.end(),compare);
        int cnt = 0;
        int last = -1e9;
        for(int i = 0; i < n; i++){
            if(arr[i].start < last){
                cnt++;
            }else
            last = arr[i].finish;
        }
        return cnt;
    }
};