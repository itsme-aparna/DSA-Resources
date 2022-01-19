class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int x = intervals[0][0];
        int y = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]<=y){
                x = min(intervals[i][0],x);
                y = max(intervals[i][1], y);
            }
            else{
                vector<int> temp;
                temp.push_back(x);
                temp.push_back(y);
                ans.push_back(temp);
                x = intervals[i][0];
                y = intervals[i][1];
            }
        }
        vector<int> temp;
        temp.push_back(x);
        temp.push_back(y);
        ans.push_back(temp);
        return ans;
    }
};