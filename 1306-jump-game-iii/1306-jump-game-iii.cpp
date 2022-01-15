class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        //dfs
        int n = size(arr);
        
        if(start<0 || start>=n || arr[start]<0)
            return false;
        
        arr[start] *= -1;
        return !arr[start] || canReach(arr, start+arr[start]) || canReach(arr, start-arr[start]);
    }
};