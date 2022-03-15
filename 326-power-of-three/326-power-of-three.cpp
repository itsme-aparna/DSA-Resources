class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0)
            return 0;
        
        float ans = (log(n)/log(3));
        
        return n == pow(3, ans);
    }
};