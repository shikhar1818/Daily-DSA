class Solution {
public:
    int fun(int n){
        vector<int> arr;
        while(n){
            int d = n%10;
            arr.push_back(d);
            n /= 10;
        }
        int sz = arr.size();
        int cnt = 0;
        for(int i = 1; i < sz-1; i++){
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1])
            cnt++;
            else if(arr[i] < arr[i-1] && arr[i] < arr[i+1])
            cnt++;
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        int s = 0;
        for(int i = num1; i <= num2; i++)
        s += fun(i);

        return s;
    }
};