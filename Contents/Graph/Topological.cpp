#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
vector<int> vec[200005];
int ind[100005];
int main(){
    IOS
    int n, m;
    cin >> n >> m;
    memset(ind, 0, sizeof(ind));
    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        ind[b]++;
        vec[a].push_back(b);
    }
    queue<int> q;
    for(int i = 1;i <= n;i++){
        if(ind[i] == 0) q.push(i);
    }
    vector<int> top;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        top.push_back(cur);
        for(auto e : vec[cur]){
            ind[e]--;
            if(ind[e] == 0){
                q.push(e);
            }
        }
    }
    if(top.size() == n){
        for(auto i : top) cout << i << ' ';
        cout << '\n';
    }
    else cout << "IMPOSSIBLE" << '\n';

    return 0;
}