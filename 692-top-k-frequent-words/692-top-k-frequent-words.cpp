#define psi pair<int, string>

class comp{
    public:
        bool operator()(const psi &p1, const psi &p2){
            if(p1.first == p2.first){
                return p1.second<p2.second;
            }
            return p1.first>p2.first;
        }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(int i=0; i<words.size(); i++){
            mp[words[i]]++;
        }
        priority_queue<psi, vector<psi>, comp> pq;
        for(auto i: mp){
            pq.push({i.second, i.first});
            if(pq.size() > k) {
                pq.pop();
    }
        }
        
        vector<string> ans(k);
  int m = k-1;

  while(pq.size() > 0) {
    ans[m--] = pq.top().second;
    pq.pop();
  }

  return ans;
    }
};