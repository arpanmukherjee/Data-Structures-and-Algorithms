#include<bits/stdc++.h>
using namespace std;

#define MAX 100005
#define INF 0x3f3f3f3f

bool vis[MAX];
int dist[MAX];
vector<int> adj[MAX];

int main()
{
    int V, E, x, y, i, src;
    queue<int> Q;
    memset(dist, INF, sizeof(dist));
    memset(vis, false, sizeof(vis));

    cout << "Enter the no of Nodes";
    cin >> V;
    cout << "Enter the no of Edges";
    cin >> E;
    for(i = 0 ; i < E ; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout << "Enter the source node:";
    cin >> src;

    Q.push(src);
    dist[src] = 0;
    while (!Q.empty())
    {
        x = Q.front();
        Q.pop();
        vis[x] = true;
        for(i = 0 ; i < adj[x].size() ; i++)
        {
            y = adj[x][i];
            if(!vis[y])
            {
                Q.push(y);
                dist[y] = min(dist[y], dist[x] + 1);
            }
        }
    }
    cout << "Distance from the source node " << src << endl;
    for(i = 0 ; i < V ; i++)
        cout << i << "\t" << dist[i] << endl;
    return 0;
}