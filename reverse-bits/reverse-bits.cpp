class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        unsigned int num = 0;
        for(int i=0; i<32; i++){
            if(n&(1<<(31-i))){
                num = ((1<<i)|num);
            }
        }
        return num;
    }
};