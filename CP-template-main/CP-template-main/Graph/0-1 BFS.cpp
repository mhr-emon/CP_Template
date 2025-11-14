// C++ program to implement 0-1 BFS 
// (Shortest Path in a Binary Weight Graph)
#include <bits/stdc++.h>
using namespace std;

vector<int> minDist(int n, int src, vector<vector<int>> &edges) {
    
    // Create adjacency list representation of the graph
    vector<vector<vector<int>>> adj(n);
    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }
    
    // Initialize distances to infinity
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    
    // Use deque for 0-1 BFS
    deque<int> dq;
    dq.push_back(src);
    
    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();
        
        // Process all adjacent vertices
        for (auto &edge : adj[u]) {
            int v = edge[0];
            int weight = edge[1];
            
            // If we can improve the distance
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                
                // If weight is 0, push to front (higher priority)
                // If weight is 1, push to back (lower priority)
                if (weight == 0)
                    dq.push_front(v);
                else
                    dq.push_back(v);
            }
        }
    }
    
    return dist;
}

int main() {
    int n, m, src;
    cin >> n >> m >> src;

    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }
    vector<int> res = minDist(n, src, edges);
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    
    return 0;
}
