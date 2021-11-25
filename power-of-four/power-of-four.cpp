class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0){
            return false;
        }
        if(n==(n&~(n-1)) && ((int)log2(n)&1)==0){
            //power of 2
            return true;
        }
        return false;
    }
};