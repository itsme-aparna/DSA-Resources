class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int, vector<pair<int, double>>> adj;
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        priority_queue<pair<double, int>> pq;
        pq.push({1.00, start});
        
        vector<double> prob(n, 0.00);
        prob[start] = 1.00;
        
        vector<bool> vis(n, false);
        
        while(!pq.empty()){
            double d = pq.top().first;
            int n = pq.top().second;
            pq.pop();
            if(vis[n]){
                continue;
            }
            vis[n] = true;
            for(auto i: adj[n]){
                int x = i.first;
                double y = i.second;
                if(y*d > prob[x]){
                    prob[x] = y*d;
                    pq.push({y*d,x});
                }
            }
            
        }
        
        return prob[end];
        
    }
};