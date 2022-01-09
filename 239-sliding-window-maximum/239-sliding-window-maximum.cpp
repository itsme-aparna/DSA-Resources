class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if(k==0)
            return result;
        priority_queue<pair<int, int>> pq;
        for(int i=0; i<nums.size(); i++){
            while(!pq.empty() && pq.top().second<= i-k)
                pq.pop();
            pq.push(make_pair(nums[i], i));
            if(i>= k-1)
                result.push_back(pq.top().first);
        }
        return result;
    }
};
