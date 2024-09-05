// BIT
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/detail/standard_policies.hpp>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const int N = 2e5 + 5;
ll bit[N], n, q;
ll query(int idx){
    ll sum = 0;
    for(int i = idx;i > 0;i -= lowbit(i))
        sum += bit[i];
    return sum;
}
void update(ll val, int idx){
    for(int i = idx;i <= n;i += lowbit(i))
        bit[i] += val;
}
int main(){
    IOS
    cin >> n >> q;
    for(int i = 1;i <= n;i++){ // 1-based
        ll in;
        cin >> in;
        update(in, i);
    }
    while(q--){
        ll o, a, b;
        cin >> o >> a >> b;
        if(o == 1){
            ll u = query(a) - query(a - 1);
            update(b - u, a);
        }
        else{
            cout << query(b) - query(a - 1) << '\n';
        }
    }

    return 0;
}