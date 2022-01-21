class Solution {
public:
    bool isPerfectSquare(int num) {
        long long i = 0;
        long long j = num;
        while(i<=j){
            long long mid = (i+j)/2;
            if((mid*mid)==num){
                return true;
            }
            else if(mid*mid>num){
                j = mid-1;
            }
            else {
                i= mid+1;
            }
        }
        return false;
    }
};