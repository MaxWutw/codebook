#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 2147483647
using namespace std;
int n, m;
vector<pair<int, int>> adj[100005];
bool visited[100005] = {false};
priority_queue<pair<int, int>> pq;
int dis[100005], parent[100005];
void solve(){ // Dijkstra
    dis[0] = 0;
    for(int i = 1;i < n;i++) dis[i] = INF;
    pq.push(make_pair(0, 0));
    while(!pq.empty()){
        auto node = pq.top();
        pq.pop();
        int v = node.second; // parent
        if(visited[v]) continue;
        visited[v] = true;
        for(auto i : adj[v]){
            int vertex = i.first, weight = i.second;
            if(visited[vertex]) continue;
            if(dis[v] + weight < dis[vertex]){
                dis[vertex] = dis[v] + weight;
                parent[vertex] = v;
                pq.push(make_pair(-dis[vertex], vertex));
            }
        }
    }
    int maxd = -1, cnt = 0;
    for(int i = 0;i < n;i++){
        if(dis[i] < INF){
            if(dis[i] > maxd) maxd = dis[i];
        }
        else cnt++;
    }
    cout << maxd << '\n' << cnt << '\n';
}
int main(){
    IOS
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    solve();
    
    return 0;
}