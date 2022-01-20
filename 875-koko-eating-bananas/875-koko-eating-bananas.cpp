class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //binary search
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while(l<r){
            int m = (l+r)>>1;
            int total = 0;
            for(auto p: piles){
                total += (p + m - 1) / m;
            }
            if (total > h)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};