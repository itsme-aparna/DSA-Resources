class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        vector<int> temp = intervals[0];
        
        for(int i=0; i<intervals.size(); i++){
            if(intervals[i][0]<= temp[1]){
                temp[1] = max(intervals[i][1], temp[1]);
            }
            else{
                ans.push_back(temp);
                temp = intervals[i];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
