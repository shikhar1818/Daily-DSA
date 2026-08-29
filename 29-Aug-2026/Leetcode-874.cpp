class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        int n = commands.size();
        int m = obstacles.size();

        set<pair<int, int>> mp;

        for (int i = 0; i < m; i++) {
            int x = obstacles[i][0];
            int y = obstacles[i][1];

            mp.insert({x, y});
        }

        int x = 0, y = 0;

        int dx = 0, dy = 1;

        int ans = 0;

        for (int i = 0; i < n; i++) {

            if (commands[i] == -2) {
                if (dx == 0) {
                    dx = -dy;
                    dy = 0;
                }
                else {
                    dy = dx;
                    dx = 0;
                }
            }

            else if (commands[i] == -1) {
                if (dx == 0) {
                    dx = dy;
                    dy = 0;
                }
                else {
                    dy = -dx;
                    dx = 0;
                }
            }

            else {
                int k = commands[i];

                for (int j = 1; j <= k; j++) {

                    if (dy == 1) {
                        if (mp.count({x, y + 1}) == 0)
                            y++;
                        else
                            break;
                    }

                    else if (dy == -1) {
                        if (mp.count({x, y - 1}) == 0)
                            y--;
                        else
                            break;
                    }

                    else if (dx == 1) {
                        if (mp.count({x + 1, y}) == 0)
                            x++;
                        else
                            break;
                    }

                    else if (dx == -1) {
                        if (mp.count({x - 1, y}) == 0)
                            x--;
                        else
                            break;
                    }

                    int dis = x * x + y * y;
                    ans = max(ans, dis);
                }
            }
        }

        return ans;
    }
};