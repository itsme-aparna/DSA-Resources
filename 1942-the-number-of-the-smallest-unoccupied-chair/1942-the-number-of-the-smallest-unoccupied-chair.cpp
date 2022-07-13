class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int targetStart = times[targetFriend][0];
        sort(times.begin(), times.end());
        int ans;
        int n = times.size();
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        priority_queue <int, vector<int>, greater<int> > chair;
        for(int i=0; i<n; i++){
            chair.push(i);
        }
        for(int i=0; i<times.size(); i++){
            while(!pq.empty() && times[i][0] >= pq.top().first){
                chair.push(pq.top().second);
                pq.pop();
            }
            int seat = chair.top();
            chair.pop();
            if(times[i][0] == targetStart){
                ans = seat;
            }
            pq.push({times[i][1], seat});
            
        }
        return ans;
    }
};