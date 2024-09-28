#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 1005;

vector<pii> adj[MAXN]; // adj[u] stores pairs {v, weight}
int dist[MAXN], sec_dist[MAXN]; // shortest and second shortest distances

void dijkstra(int s, int n){
    // Min-heap to store {distance, node}
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    fill(dist, dist + n + 1, INF);
    fill(sec_dist, sec_dist + n + 1, INF);

    dist[s] = 0;
    pq.push({0, s});

    while(!pq.empty()){
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // If we found a path longer than the second shortest, skip it
        if (sec_dist[u] < d) continue;

        for (auto &edge : adj[u]){
            int v = edge.first;
            int w = edge.second;

            int new_dist = d + w;

            // If this gives a new shortest path to v
            if(new_dist < dist[v]){
                sec_dist[v] = dist[v];
                dist[v] = new_dist;
                pq.push({dist[v], v});
                pq.push({sec_dist[v], v});
            }
            // If this gives a new second shortest path to v
            else if(new_dist > dist[v] && new_dist < sec_dist[v]){
                sec_dist[v] = new_dist;
                pq.push({sec_dist[v], v});
            }
        }
    }
}

int main() {
    IOS
    int t;
    cin >> t;
    while(t--){
        int n, m, s, d;
        cin >> n >> m >> s >> d;

        // Reset adjacency list
        for(int i = 1; i <= n; i++) adj[i].clear();

        for(int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // If the graph is undirected
        }

        dijkstra(s, n);

        if(sec_dist[d] == INF) cout << -1 << '\n'; // No second shortest path
        else cout << sec_dist[d] << '\n';
    }

    return 0;
}