class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<int> adj[numCourses];
        vector<int> ans;
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int> q;
        
        for(int i=0; i<numCourses; i++){
            if(indegree[i] ==0)
                q.push(i);
        }
            while(!q.empty()){
                int node = q.front();
                ans.push_back(node);
                q.pop();
                for(auto it: adj[node]){
                    indegree[it]--;
                    if(indegree[it]==0){
                        q.push(it);
                    }
                }
            
            }
            
        for(int i=0; i<numCourses; i++){
            if(indegree[i]!=0){
                vector<int> dum;
                return dum;
            }
        }
        return ans;
    }
};