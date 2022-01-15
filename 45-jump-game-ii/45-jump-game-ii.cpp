class Solution {
public:
    int jump(vector<int>& nums) {
        int max_reachable_idx = 0;
        int cur_max_idx = 0;
        int jump_cnt = 0;
        
        for(int i = 0; i < nums.size(); ++i){
            max_reachable_idx = max(max_reachable_idx, i+nums[i]);
            if(i >= cur_max_idx && i != nums.size()-1){
                jump_cnt++;
                cur_max_idx = max_reachable_idx;
            }
        }
        
        return jump_cnt;
    }
};