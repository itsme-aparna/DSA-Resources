class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        int y = 0;
        for(int i=0; i<n; i++){
            if(i%2 == 0){
                x = max(x+nums[i], y);
            }
            else{
                y = max(x, y+nums[i]);
            }
        }
        return max(x,y);
    }
};
