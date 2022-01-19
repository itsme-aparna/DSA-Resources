class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0){
            return;
        }
        int ptr1=0;
        int ptr2 = 0;
        while(ptr1<m){
            if(nums1[ptr1]>nums2[ptr2]){
                swap(nums1[ptr1],nums2[ptr2]);
                
                sort(nums2.begin(), nums2.end());
                ptr1++;
            }
            else{
                ptr1++;
            }
        }
        int i=m;
        int j =0;
        while(i<m+n, j<n){ 
            nums1[i]= nums2[j];
            i++;
            j++;
        }
        
    }
};