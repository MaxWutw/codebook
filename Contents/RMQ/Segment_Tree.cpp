#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define L(x) (x << 1)
#define R(x) ((x << 1) | 1)
using namespace std;
typedef long long ll;
ll seg[500005 << 2], lazy[500005 << 2];
int n, q;
void init(){
    memset(seg, 0, sizeof(seg));
    memset(lazy, 0, sizeof(lazy));
}
void build(int x, int l, int r){
    if(l == r){
        cin >> seg[x];
        return;
    }
    int mid = (l + r) >> 1;
    build(L(x), l, mid);
    build(R(x), mid + 1, r);
    seg[x] = seg[L(x)] + seg[R(x)];
}
void push(int pos, int size){
    lazy[L(pos)] += lazy[pos];
    lazy[R(pos)] += lazy[pos];
    seg[pos] = seg[pos] + lazy[pos] * size;
    lazy[pos] = 0;
}
void modify(int x, int l, int r, int ql, int qr, int val){
    if(lazy[x]) push(x, (r - l) + 1);
    // seg[x] = seg[L(x)] + (mid - l) * lazy[L(x)] + seg[R(x)] + (r - mid) * lazy[R(x)];
    seg[x] += val * (qr - ql + 1);
    if(ql <= l && qr >= r){
        lazy[x] += val;
        return;
    }
    int mid = (l + r) >> 1;
    if(qr <= mid) modify(L(x), l, mid, ql, qr, val);
    else if(ql > mid) modify(R(x), mid + 1, r, ql, qr, val);
    else{
        modify(L(x), l, mid, ql, mid, val);
        modify(R(x), mid + 1, r, mid + 1, qr, val);
    }
}
ll query(int x, int l, int r, int ql, int qr){
    if(ql <= l && qr >= r) return seg[x] + lazy[x] * (r - l);
    if(lazy[x]) push(x, (r - l) + 1);
    int mid = (l + r) >> 1;
    if(qr <= mid) return query(L(x), l, mid, ql, qr);
    else if(ql > mid) return query(R(x), mid + 1, r, ql, qr);
    else return query(L(x), l, mid, ql, mid) + query(R(x), mid + 1, r, mid + 1, qr);
}
int main(){
    IOS
    init();
    cin >> n;
    build(1, 1, n);
    cin >> q;
    while(q--){
        int v, x, y, k;
        cin >> v;
        if(v == 1){
            cin >> x >> y >> k;
            modify(1, 1, n, x, y, k);
        }
        else{
            cin >> x >> y;  
            ll ans = query(1, 1, n, x, y);
            cout << ans << '\n';
        }
    }

    return 0;
}