#include <bits/stdc++.h>
using namespace std;

vector<int> BFS(int V, vector<int> adj[])
{
    vector<int> bfs;
    vector<int> vis(V, 0);
    queue<int> q;

    for(int i = 0; i<V; i++)
    {
        if (!vis[i])
        {
            q.push(i);
            vis[i] = 1;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for (auto it : adj[node])
                {
                    if (!vis[it])
                    {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }
    return bfs;
}

int main()
{
    int tc,i,j,x,n,m,k,V, E;
    cout<<"Enter number of vertex ans edge : ";
    cin>>V>>E;
    vector<int> adj[V];
    cout<<"Enter edges : ";
    for (i = 0; i < E; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans = BFS(V, adj);
    for (int i = 0; i < ans.size(); i++)
        cout<<ans[i]<<" ";

    cout << endl;
}

