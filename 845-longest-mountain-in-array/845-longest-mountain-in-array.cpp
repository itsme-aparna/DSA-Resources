class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int max_cnt = 0;
        for(int i=1; i<arr.size()-1; i++){
            if(arr[i-1]<arr[i] && arr[i+1]<arr[i]){
                int j = i; int cnt = 1;
                while(j<arr.size()-1 && arr[j+1]<arr[j]){
                    j++;
                    cnt++;
                }
                j = i;
                while(j>0 && arr[j-1]<arr[j]){
                    j--;
                    cnt++;
                }
                max_cnt = max(max_cnt, cnt);
            }
            
        }
        return max_cnt;
    }
};