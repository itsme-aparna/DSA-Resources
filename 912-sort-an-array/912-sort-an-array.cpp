class Solution {
public:
    
    void merge(vector<int>& nums, int l, int r, int mid){
        vector<int> temp( r-l+1);
        int ptr1 = l;
        int ptr2 = mid+1;
        int k = 0;
        //merge
        while(ptr1<= mid && ptr2<= r){
            if(nums[ptr1]<= nums[ptr2]){
                temp[k++] = nums[ptr1];
                ptr1++;
            }
            else{
                temp[k++] = nums[ptr2];
                ptr2++;
            }
        }
        
        while(ptr1<= mid){
            temp[k++] = nums[ptr1++];
        }
        while(ptr2<=r){
            temp[k++] = nums[ptr2++];
        }
        for(int i=0; i<k; i++){
            nums[l+i] = temp[i];
        }
        
    }
    
    void mergeSort(vector<int>& nums, int l, int r){
        if(l>=r)
            return;
        int mid = l + ((r-l)/2);
        mergeSort(nums, l, mid);
        mergeSort(nums, mid+1, r);
        merge(nums, l, r, mid);
        
    }
    
    vector<int> sortArray(vector<int>& nums) {
        //insertion sort
        // for(int i=1; i<nums.size(); i++){
        //     int temp = nums[i];
        //     int j = i-1;
        //     while(j>=0 && nums[j]>temp){
        //         nums[j+1] = nums[j];
        //         j--;
        //     }
        //     nums[j+1] = temp;
        // }
        // return nums;
        
        
        //merge sort
        int l =0;
        int r = nums.size()-1;
        mergeSort(nums, l, r);
        return nums;
    }
    
};