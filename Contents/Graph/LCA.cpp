#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int n, q;
vector<int> vec[N];
int p[20][N], in[N], out[N];
bool valid(int a, int b){
    return (in[a] <= in[b] && out[b] <= out[a]);
}
void dfs(int cur, int par){
    static int t = 0;
    p[0][cur] = par;
    in[cur] = t++;
    for(auto e : vec[cur]){
        dfs(e, cur);
    }
    out[cur] = t++;
}
int lca(int a, int b){
    if(valid(a, b)) return a;
    for(int i = 19;i >= 0;i--){
        if(!valid(p[i][a], b)) a = p[i][a];
    }
    return p[0][a];
}
int main(){
    IOS
    cin >> n >> q;
    for(int i = 2;i <= n;i++){
        int e;
        cin >> e;
        vec[e].push_back(i);
    }
    dfs(1, 1);
    for(int i = 1;i < 20;i++){
        for(int j = 1;j <= n;j++){
            p[i][j] = p[i - 1][p[i - 1][j]];
        }
    }
    while(q--){
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }

    return 0;
}
