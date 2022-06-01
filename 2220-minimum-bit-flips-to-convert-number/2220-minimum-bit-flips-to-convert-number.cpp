class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start^goal;
        int cnt = 0;
        while(x){
            cnt++;
            x = x&(x-1);
        }
        return cnt;
    }
};