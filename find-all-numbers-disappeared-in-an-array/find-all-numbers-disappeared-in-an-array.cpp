class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        vector<bool> visited(n, false);
        for(int i=0; i<n; i++){
            visited[nums[i]-1]=true;
        }
        for(int i=0; i<n; i++){
            if(visited[i]==false)
                ans.push_back(i+1);
        }
        return ans;
    }
};