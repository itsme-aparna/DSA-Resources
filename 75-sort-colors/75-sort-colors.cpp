class Solution {
public:
    void sortColors(vector<int>& nums) {
        int pt1 = 0;
        int pt2 = nums.size()-1;
        int pt =0;
        while(pt1<=pt2){
            switch(nums[pt1]){
                case 0:
                    swap(nums[pt1], nums[pt]);
                    pt++;
                    pt1++;
                    break;
                case 1:
                    pt1++;
                    break;
                case 2:
                    swap(nums[pt1], nums[pt2]);
                    
                    pt2--;
                    break;
            }
        }
    }
};