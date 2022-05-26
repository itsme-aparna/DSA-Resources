class Solution {
public:
    bool hasAlternatingBits(int n) {
        int x =n&1;
        n>>=1;
        while(n){
            if((n&1)!=x){
                x = n&1;
                n>>=1;
            }
            else return false;
        }
        return true;
    }
};