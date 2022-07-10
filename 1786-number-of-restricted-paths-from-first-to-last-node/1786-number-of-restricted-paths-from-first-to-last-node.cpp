class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        long mod = 1e9 + 7;
        unordered_map<int, vector<pair<int, int>>> adj;
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        
        priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;
        vector<long> dis(n+1, INT_MAX);
        vector<long> cnt(n+1, 0);
        dis[n] = 0;
        cnt[n] = 1;
        pq.push({0, n});
        
        while(!pq.empty()){
            auto [d, n] = pq.top();
            pq.pop();
            if(d> dis[n])
                continue;
            for(auto &[x, y]: adj[n]){
                if(dis[x]>y + d){
                    dis[x] = y+ d;
                    pq.push({dis[x], x});
                    
                }
                if(d>dis[x]){
                    cnt[n] = (cnt[x] + cnt[n])% mod;
                }
            }
        }
        
        return cnt[1];
    }
};