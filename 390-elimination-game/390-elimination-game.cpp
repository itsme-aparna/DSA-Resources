class Solution {
public:
    int findLast(int n, bool type) {
        if(n==1)
            return 1;
        int res = (findLast((n>>1), !type)<<1);
        if(type || n&1)
            return res;
        return res-1;
    }
    int lastRemaining(int n) {
        return findLast(n, true);
    }
};