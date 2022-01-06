class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> mp;
        for(int i = 0; i<trips.size(); i++){
            mp[trips[i][1]] += trips[i][0];
            mp[trips[i][2]] -= trips[i][0];
        }
        
        for(auto it : mp){
            capacity -= it.second;
            if(capacity<0)
                return false;
        }
        return true;
    }
};
