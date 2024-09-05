#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
ll mod = 1000000007;
struct Matrix{
    ll mat[2][2] = {{0}};
    Matrix operator * (Matrix &inp){
        Matrix tmp;
        for(int i = 0;i < 2;i++){
            for(int j = 0;j < 2;j++){
                for(int k = 0;k < 2;k++){
                    tmp.mat[i][j] = ((tmp.mat[i][j] + (mat[i][k] % mod) * (inp.mat[k][j] % mod)) % mod) % mod;
                }
            }
        }
        return tmp;
    }
};
Matrix base;
Matrix fast_pow(int n){
    if(n == 1) return base;
    if(n % 2 == 0){
        Matrix res = fast_pow(n >> 1);
        return res * res;
    }
    Matrix res = fast_pow(n >> 1);
    return base * res * res;
}
int main(){
    IOS
    base.mat[0][0] = 1;
    base.mat[0][1] = 1;
    base.mat[1][0] = 1;
    base.mat[1][1] = 0;
    Matrix output = fast_pow(20);
    cout << output.mat[0][0] << '\n';

    return 0;
}