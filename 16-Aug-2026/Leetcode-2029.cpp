class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n = stones.size();
        int a = 0,b = 0,c = 0;
        for(int i = 0; i < n; i++){
            if(stones[i]%3 == 0)
            a++;
            else if(stones[i]%3 == 1)
            b++;
            else
            c++;
        }
        if(a%2 == 0)
        return (b && c);

        return abs(b-c)>2;

    }
};