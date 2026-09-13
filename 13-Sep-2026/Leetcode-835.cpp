class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<vector<int>> a1;
        vector<vector<int>> a2;

        vector<vector<int>> mp(2*n-1,vector<int>(2*n-1,0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(img1[i][j] == 1)
                a1.push_back({i,j});
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(img2[i][j] == 1)
                a2.push_back({i,j});
            }
        }
        int n1 = a1.size();
        int n2 = a2.size();
        int ans = 0;
        int x1,y1,x2,y2,dx,dy;
        for(int i = 0; i < n1; i++){
            x1 = a1[i][0];
            y1 = a1[i][1];
            for(int j = 0; j < n2; j++){
                x2 = a2[j][0];
                y2 = a2[j][1];
                dx = x2-x1+n-1;
                dy = y2-y1+n-1;
                mp[dx][dy]++;
                ans = max(ans,mp[dx][dy]);
            }
        }
        return ans;
    }
};