class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int> > adj_list(n);
                vector<int> counters(n, 0);
                for (auto &e : edges) {
                    adj_list[e[0]].push_back(e[1]);
                    adj_list[e[1]].push_back(e[0]);
                    ++counters[e[0]];
                    ++counters[e[1]];
                }
                queue<int> q;
                for (int i = 0; i < n; ++i) {
                    if (counters[i] <= 1) {
                        q.push(i);
                    }
                }
                while (n > 2) {
                    int num_leafs = q.size();
                    n -= num_leafs;
                    for (int i = 0; i < num_leafs; ++i) {
                        int node = q.front();
                        q.pop();
                        for (auto neighbor : adj_list[node]) {
                            if (--counters[neighbor] == 1) {
                                q.push(neighbor);
                            }
                        }
                    }
                }
                vector<int> res;
                while (!q.empty()) {
                    res.push_back(q.front());
                    q.pop();
                }
                return res;
        
        
    }
};