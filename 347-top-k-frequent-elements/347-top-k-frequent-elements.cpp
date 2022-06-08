class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        for(auto i: mp){
            pq.push({i.second, i.first});
        }
        vector<int> ans;
        while(k--){
            if(!pq.empty()){
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        return ans;
    }
};