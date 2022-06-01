class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int temp = 0;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            ans.push_back(temp+nums[i]);
            temp += nums[i];
        }
        return ans;
    }
};