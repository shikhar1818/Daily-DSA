class Solution {
public:
    struct box{
        int boxes;
        int units;
    };
    static bool compare(box a, box b){
        return a.units > b.units;
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        vector<box> arr(n);
        for(int i = 0; i < n; i++){
            arr[i].boxes = boxTypes[i][0];
            arr[i].units = boxTypes[i][1];
        }
        sort(arr.begin(),arr.end(),compare);
        int i = 0;
        int rem = truckSize;
        int ans = 0;
        while(rem && i < n){
            if(rem > arr[i].boxes){
                ans += arr[i].boxes*arr[i].units;
                rem -= arr[i].boxes;
                i++;
            }else{
                ans += rem*arr[i].units;
                rem = 0;
            }

        }
        return ans;
    }
};