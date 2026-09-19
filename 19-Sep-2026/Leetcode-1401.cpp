class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {   
        if((xCenter <= x2 && xCenter >= x1) && (yCenter <= y2 && yCenter >= y1))
        return true;

        int dis = INT_MAX;
        for(int i = x1; i <= x2; i++){
            int a = (i-xCenter)*(i-xCenter) + (y2-yCenter)*(y2-yCenter);
            int b = (i-xCenter)*(i-xCenter) + (y1-yCenter)*(y1-yCenter);
            dis = min(dis,min(a,b));
        }
        
        for(int i = y1; i <= y2; i++){
            int a = (x1-xCenter)*(x1-xCenter) + (i-yCenter)*(i-yCenter);
            int b = (x2-xCenter)*(x2-xCenter) + (i-yCenter)*(i-yCenter);
            dis = min(dis,min(a,b));
        }
        return dis <= (radius*radius);
    }
};