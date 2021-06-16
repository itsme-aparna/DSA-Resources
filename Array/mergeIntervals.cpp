#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeInterval(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
            for(auto interval: intervals){ 
            if(merged.empty()||merged.back()[1]<interval[0]){
                merged.push_back(interval);
            }
            else{
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
            }
        return merged;
    }
};

int main(){
    vector<vector<int>> intervals
    {
        {1, 2},
        {1, 5},
        {7, 8}
    };
    Solution s1;
    vector<vector<int>> ans=s1.mergeInterval(intervals);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<endl;
        }
    }
    return 0;
}