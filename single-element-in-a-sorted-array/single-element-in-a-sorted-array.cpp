class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xor1 = nums[0];
        for(int i=1; i<nums.size(); i++){
            xor1 = xor1^nums[i];
        }
        return xor1;
    }
};