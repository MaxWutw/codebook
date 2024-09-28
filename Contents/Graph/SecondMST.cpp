#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int anc[105], sz[105];
struct Edge{
    int a, b, c;
};
int Find(int a){
    return (anc[a] == a ? a : anc[a] = Find(anc[a]));
}
bool merge(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a == b) return false;
    if(sz[a] < sz[b]) swap(a, b);
    anc[b] = a;
    sz[a] += sz[b];
    return true;
}
int main(){
    IOS
    int t;
    cin >> t;
    while(t--){
        int n, m;
        vector<Edge> edge;
        cin >> n >> m;
        vector<pair<int, int> > vec[105];
        for(int i = 0;i < m;i++){
            int a, b, c;
            cin >> a >> b >> c;
            edge.push_back({a, b, c});
        }
        for(int i = 1;i <= n;i++){
            sz[i] = 0;
            anc[i] = i;
        }
        sort(edge.begin(), edge.end(), [&](Edge &u, Edge &v){return u.c < v.c;});
        int cost1 = 0, cnt = 0;
        vector<int> mst;
        for(int i = 0;i < edge.size();i++){
            if(merge(edge[i].a, edge[i].b)){
                cost1 += edge[i].c;
                mst.push_back(i);
                if(++cnt == n - 1) break;
            }
        }
        int cost2 = INF;
        for(int i = 0;i < mst.size();i++){
            cnt = 0;
            int res = 0;
            for(int i = 1;i <= n;i++) anc[i] = i;
            for(int j = 0;j < edge.size();j++){
                if(mst[i] == j) continue;
                if(merge(edge[j].a, edge[j].b)){
                    res += edge[j].c;
                    if(++cnt == n - 1){
                        cost2 = min(cost2, res);
                        break;
                    }
                }
            }
        }

        cout << cost1 << ' ' << cost2 << '\n';
    }

    return 0;
}
