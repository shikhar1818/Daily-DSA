class Solution {
  public:
    int setBit(int n) {
        int a = 1;
        while(n & a){
            a = a << 1;
        }
        return (n|a);
    }
};