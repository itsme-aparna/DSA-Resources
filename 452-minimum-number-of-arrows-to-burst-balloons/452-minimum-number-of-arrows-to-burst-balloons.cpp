class Solution {
public:
    //[[1,6],[2,8],[7,12],[10,16]]
    //updated pair: [2, 6] : intersection
    //next update: [7, 12] : new pair, with no intersection
    // p = [1, 6]
    // p = [2, 6]
    // p = [7, 12]
    // p = [10, 12]
    
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==1)
            return 1;
        sort(points.begin(), points.end());
        int ans = 1;
        pair<int, int> p;
        p.first = points[0][0];
        p.second = points[0][1];
         for(int i=1; i<points.size(); i++){
            if(points[i][0]<=p.second){
                //update the pair and continue the iteration
                p.first = max(p.first, points[i][0]);
                p.second = min(p.second, points[i][1]);
            }
            else{
                ans++;
                p.first = points[i][0];
                p.second = points[i][1];
            }   
            
        }
        return ans;
    }
};