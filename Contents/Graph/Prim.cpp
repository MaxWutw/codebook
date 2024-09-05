#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int n, m, dis[10005], parent[10005];
bool visited[10005] = {false};
vector<pair<int, int> > adj[100005];
int main(){
    IOS
    // freopen("input.in", "r", stdin);
    cin >> n >> m;
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    memset(parent, -1, sizeof(parent));
    for(int i = 0;i < m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int start = 0;
    dis[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({dis[start], start});
    while(!pq.empty()){
        pair<int, int> cur = pq.top();
        pq.pop();
        if(visited[cur.second]) continue;
        visited[cur.second] = true;
        for(auto i : adj[cur.second]){
            if(visited[i.first]) continue;
            if(dis[i.first] > i.second){
                dis[i.first] = i.second;
                parent[i.first] = cur.second;
                pq.push({dis[i.first], i.first});
            }
        }
    }
    int cost = 0, err = 0;
    for(int i = 0;i < n;i++){
        if(dis[i] < 0x3f3f3f3f) cost += dis[i];
        else err++;
    }
    cout << (err ?  -1 : cost) << "\n";
    // for(int i = 0;i < n;i++) cout << dis[i] << ' ';

    return 0;
}