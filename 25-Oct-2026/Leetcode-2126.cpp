class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        long long m = 1LL*mass;
        sort(asteroids.begin(),asteroids.end());
        for(int i = 0; i < n; i++){
            if(m < asteroids[i])
            return false;
            m += 1LL*asteroids[i];
        }
        return true;
    }
};




// Second approach using count sort

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        int maxmass = 0;
        for(int i : asteroids)
        maxmass = max(maxmass,i);

        vector<int> arr(maxmass+1,0);
        for(int i : asteroids)
        arr[i]++;

        long long m = mass;
        for(int i = 0; i <= maxmass; i++){
            if(arr[i] > 0){
                if(m < i)
                return false;
                m += 1LL*i*arr[i];
            }
        }
        return true;
    }
};