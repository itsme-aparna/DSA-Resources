/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    void dfs(Node* curr, Node* n, vector<Node*> &vis){
        vis[n->val] = n;
        
        for(auto i: curr->neighbors){
            if(vis[i->val]== NULL){
                Node* nNode = new Node(i->val);
                (n->neighbors).push_back(nNode);
                dfs(i, nNode, vis);
            }
            else{
                (n->neighbors).push_back(vis[i->val]);
            }
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        vector<Node*> vis(101, NULL);
        Node* clone = new Node(node->val);
        vis[node->val] = clone;
        
        for(auto i: node->neighbors){
            if(vis[i->val]==NULL){
                Node* nNode = new Node(i->val);
                (clone->neighbors).push_back(nNode);
                dfs(i, nNode, vis);
            }
            else{
                (clone->neighbors).push_back(vis[i->val]);
            }
        }
        return clone;
    }
};