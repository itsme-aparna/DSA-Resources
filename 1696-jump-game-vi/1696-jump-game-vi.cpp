class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q; // monotone queue stores the elements in decreasing order, thenmax element being on the front of the deque.
        
        long long curr = 0;
        
        for(int i= n-1; i>=0; i--){
            curr = nums[i] + (q.empty() ? 0 : nums[q.front()]); // since max element will be at the front, so keep adding this element into curr.
            
            while(!q.empty() && curr>nums[q.back()]){
                q.pop_back(); // removing all indexes which are less than the curr element since they are useless
            }
            q.push_back(i); // pushing the current element
            
            while(q.front()>= i+k){
                q.pop_front(); // removing all indexes that lie out of range of k
            }    
            nums[i] = curr; // max score obtained till now is stored in nums array, so that it can be reused.
        }
        return curr;
        
    }
};