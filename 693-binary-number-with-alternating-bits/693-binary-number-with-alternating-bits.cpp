class Solution {
public:
    bool hasAlternatingBits(int n) {
        int x =n&1; // here x is equal to the value at last bit of n
        n>>=1;
        while(n){
            if((n&1)!=x){ // if its not equal then alternating bits are present
                x = n&1; // update x with the last bit of n
                n>>=1; // right shift/ move to prev bit 
            }
            else return false;
        }
        return true;
    }
};