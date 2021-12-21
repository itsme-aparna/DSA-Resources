class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> ans;
        int globalDiff = INT_MAX;
        
        for(int i=0; i<n-1; i++){
            if(abs(arr[i]-arr[i+1]) < globalDiff){
                ans.erase(ans.begin(), ans.end());
                vector<int> temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[i+1]);
                ans.push_back(temp);
                globalDiff = abs(arr[i]-arr[i+1]);
            }
            else if(abs(arr[i]- arr[i+1]) == globalDiff){
                vector<int> temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[i+1]);
                ans.push_back(temp);
            }
            else{
                continue;
            }
        }
        return ans;
    }
};