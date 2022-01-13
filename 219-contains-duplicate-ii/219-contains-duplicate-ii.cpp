class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]].push_back(i);
            
        }
        for(int i=0; i<nums.size(); i++){
            if(mp[nums[i]].size()>=2){
                vector<int> v = mp[nums[i]];
                
                for(int j=1; j<v.size(); j++){
                    if(abs(v[j-1]-v[j])<=k){
                    return true;
                }
                }
                
            }
                
        }
        return false;
    }
};