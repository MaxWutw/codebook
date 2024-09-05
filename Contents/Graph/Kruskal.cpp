#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int parent[10005];
struct Edge{
    int u, v, w;
    bool operator < (Edge &b){
        return w < b.w;
    }
};
int query(int a){
    if(parent[a] == -1) return a;
    return parent[a] = query(parent[a]);
}
bool merge(int a, int b){
    int r1 = query(a);
    int r2 = query(b);
    if(r1 == r2) return false;
    if(parent[r1] < parent[r2]) parent[r2] = r1;
    else parent[r1] = r2;
    return true;
}
int main(){
    IOS
    int n, m;
    memset(parent, -1, sizeof(parent));
    cin >> n >> m;
    vector<Edge> adj;
    for(int i = 0;i < m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj.push_back({u, v, w});
    }
    sort(adj.begin(), adj.end());
    // for(int i = 0;i < m;i++) cout << adj[i].w << ' ';
    int cost = 0, n_edge = 0;
    for(Edge e : adj){
        if(merge(e.u, e.v)){
            cost += e.w;
            n_edge++;
        }
    }
    if(n_edge == n - 1) cout << cost << '\n';
    else cout << -1 << '\n';

    return 0;
}