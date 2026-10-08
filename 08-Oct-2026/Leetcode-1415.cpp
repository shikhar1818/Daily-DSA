class Solution {
public:
void fun(int i,string &s, int n, vector<string>& arr){
    if(i == n){
        arr.push_back(s);
        return;
    }
    if(i == 0){
        s.push_back('a');
        fun(i+1,s,n,arr);
        s.pop_back();
        s.push_back('b');
        fun(i+1,s,n,arr);
        s.pop_back();
        s.push_back('c');
        fun(i+1,s,n,arr);
        s.pop_back();
    }
    else{
        if(s[i-1] == 'a'){
            s.push_back('b');
            fun(i+1,s,n,arr);
            s.pop_back();
            s.push_back('c');
            fun(i+1,s,n,arr);
            s.pop_back();
        }
        if(s[i-1] == 'b'){
            s.push_back('a');
            fun(i+1,s,n,arr);
            s.pop_back();
            s.push_back('c');
            fun(i+1,s,n,arr);
            s.pop_back();
        }
        if(s[i-1] == 'c'){
            s.push_back('a');
            fun(i+1,s,n,arr);
            s.pop_back();
            s.push_back('b');
            fun(i+1,s,n,arr);
            s.pop_back();
        }
    }
}
    string getHappyString(int n, int k) {
        vector<string> arr;
        string s = "";
        fun(0,s,n,arr);
        int m = arr.size();
        if(k > m)
        return "";
        return arr[k-1];
    }
};