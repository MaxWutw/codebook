#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
int n, m, arr[N], dp[35][N];
void sparse_table(int n){
    for(int i = 1;i <= 31;i++){
        for(int j = 0;(j + (1LL << (i - 1))) < n;j++){
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + (1LL << (i - 1))]);
        }
    }
}
int query(int l, int r){
    int idx = __lg(r - l + 1);
    return max(dp[idx][l], dp[idx][r - (1LL << idx) + 1]);
}
int main(){
    IOS
    cin >> n;
    for(int i = 0;i < n;i++) cin >> arr[i];
    cin >> m;
    for(int i = 0;i < n;i++) dp[0][i] = arr[i];
    sparse_table(n);
    while(m--){
        int l, r;
        cin >> l >> r;
        if(l > r) swap(l, r);
        l--, r--;
        cout << query(l, r) << '\n';
    }

    return 0;
}