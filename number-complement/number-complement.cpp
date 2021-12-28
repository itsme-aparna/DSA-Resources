class Solution {
public:
    int findComplement(int num) {
        uint mask = -1;                             
        while(mask & num) mask <<= 1;               
        return ~mask ^ num;                         
    }
};