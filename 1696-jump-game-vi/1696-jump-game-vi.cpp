class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        long long curr = 0;
        
        for(int i= n-1; i>=0; i--){
            curr = nums[i] + (q.empty() ? 0 : nums[q.front()]);
            
            while(!q.empty() && curr>nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
            
            while(q.front()>= i+k){
                q.pop_front();
            }    
            nums[i] = curr;
        }
        return curr;
        
    }
};