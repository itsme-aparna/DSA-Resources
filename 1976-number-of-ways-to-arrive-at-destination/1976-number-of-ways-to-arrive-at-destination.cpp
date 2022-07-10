class Solution {
public:
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<long long, vector<pair<long long, long long>>> adj;
        for(int i=0; i<roads.size(); i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        vector<long long> dist(n, LONG_MAX);
        vector<long long> ways(n);
        ways[0] = 1;
        dist[0] = 0;
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            long long d = pq.top().first;
            long long n = pq.top().second;
            pq.pop();
            for(auto i: adj[n]){
                long long x = i.first;
                long long y = i.second;
                
                if(dist[x]> d + y){
                    dist[x] = d+y;
                    ways[x] = ways[n];
                    pq.push({dist[x], x});
                    
                }
                else if(dist[x] == d + y){
                    ways[x] = (ways[x] + ways[n])% mod;
                }
            }
        }
        
        return ways[n-1];
        
    }
};