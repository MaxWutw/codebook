#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll fast_pow(int base, int exp){
    ll res = 1;
    while(exp > 0){
        if(exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}
int main(){
    IOS
    int base = 3, exp = 15;
    cout << fast_pow(base, exp) << '\n';

    return 0;
}