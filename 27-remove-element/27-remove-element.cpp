class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // two pointer
        int i = 0;
        int j = nums.size()-1;
        int n = nums.size();
        if(n==0){
            return {};
        }
        if(n==1 && nums[0] == val)
            return 0;
        int x = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == val){
                x++;
            }
        }
        if(x==n){
            return 0;
        }
        else if(n==1 && nums[0] != val)
            return 1;
        while(true){
            if(nums[j]!= val){
                break;
            }
            j--;
        }
        while(i<=j){
            if(nums[i]==val){
                swap(nums[i], nums[j]);
                while(true){
                    if(nums[j]!= val){
                        break;
                    }
                    j--;
                }
                
            }
            i++;
            
        }
        return i;
    }
};