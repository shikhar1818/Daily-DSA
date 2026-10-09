class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n = queries.size();
        int m = points.size();
        vector<int> ans(n);
        int cnt;
        int x1,y1,x2,y2,r,dis;
        for(int i = 0; i < n; i++){
            cnt = 0;
            x1 = queries[i][0];
            y1 = queries[i][1];
            r = queries[i][2];
            for(int j = 0; j < m; j++){
                x2 = points[j][0];
                y2 = points[j][1];
                dis = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
                if(dis <= r*r)
                cnt++;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};