class Solution {
public:
    
    long magicno(long x, long LCM, long A, long B){
        return (x/A)+(x/B)-(x/LCM);
    }
    const int MOD = 1e9+7;
    int nthMagicalNumber(int n, int a, int b) {
        long LCM = lcm(a, b), L = min(a, b), R = n*L, mid, ans;
        while(L<=R){
            mid = L + (R-L)/2;
            if(magicno(mid, LCM, a, b)<n) L = mid+1;
            else R = mid-1, ans = mid;
        }
        return ans%MOD;
    }
};



