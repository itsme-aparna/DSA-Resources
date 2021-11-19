class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x^y;
        int res=0;
        while(n){
            res++;
            n = n&(n-1);
        }
        return res;
    }
};