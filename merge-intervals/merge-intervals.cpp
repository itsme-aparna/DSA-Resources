class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.size()==0)
            return ans;
        sort(intervals.begin(), intervals.end());
        vector<int> temp = intervals[0];
        for(auto i: intervals){
            if(temp[1]>=i[0]){
                temp[0] = min(temp[0], i[0]);
                temp[1] = max(temp[1], i[1]);
            }
            else{
                ans.push_back(temp);
                temp = i;
            }
            
        }
        ans.push_back(temp);
        return ans;
    }
};