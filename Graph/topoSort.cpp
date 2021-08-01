#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int>* adj;

public:
   Graph(int V);
   void addEdge(int u, int v);
   void topologicalSort();

};

Graph:: Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(u);
}

void Graph:: topologicalSort(){
    vector<int> in_degree(V, 0);

    for(int u=0; u<V; u++){
        for(auto it: adj[u])
            in_degree[it]++;
    }

    queue<int> q;
    for(int i=0; i<V; i++){
        if(in_degree[i]==0)
            q.push(i);
    }

    int count =0;
    vector<int> top_order;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        top_order.push_back(u);
        for(auto itr:adj[u]){
            if(--in_degree[itr]==0)
                q.push(itr);
        }
        count++;
    }
    if(count!=V){
        cout<<"Cycle in graph";
        return;
    }

    for(int i=0; i<top_order.size();i++){
        cout<<top_order[i]<<"";
    cout<<endl;
    }
}

int main(){
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is a Topological Sort of\n";
    g.topologicalSort();

    return 0;
}