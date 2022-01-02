class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res = 0;
        vector<int> mp(60, 0);
        
        for(int t: time){
            t = t%60;
            int diff = 60- t;
            
            if(diff == 60)
                diff = 0;
            res+= mp[diff];
            mp[t]++;
        }
        return res;
    }
};