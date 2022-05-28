class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        int n = nums.size();
        int pre = 1;
        for(int i=0; i<n-1; i++){
            pre *= nums[i];
            ans[i+1] = pre;
        }
        
        int post = 1;
        for(int i = n-1; i>=1; i--){
            post *= nums[i];
            ans[i-1]*= post;
        }
        
        return ans;
    }
};