class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reach = 0;
        for(int i=0; i<=reach; i++){
            reach = max(reach, nums[i]+i);
            if(reach>= n-1){
                return true;
            }
        }
        return false;
    }
};
