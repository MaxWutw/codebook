#include <iostream>
#include <cstring>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int spf[1000005], ans[1000005];
void sieve(){
    memset(spf, 0, sizeof(spf));
    for (int i = 0; i <= 1000000; i++) ans[i] = 1;
    spf[1] = 1;
    for(long long i = 2;i <= 1000000;i++){
        if(!spf[i]){
            spf[i] = i;
            for(long long j = i * i;j <= 1000000;j+=i){
                if(!spf[j]){
                    spf[j] = i;
                }
            }
        }
    }   
    for(long long i = 2;i <= 1000000;i++){
        int tmp = i;
        while(tmp != 1){ 
            int cnt = 0, f = spf[tmp];
            while(tmp % f == 0){ 
                tmp /= spf[tmp];
                cnt++;
            }
            ans[i] *= (cnt + 1); 
        }
    }   
    int maxn = 2, maxans = ans[2];
    for(long long i = 2;i <= 1000000;i++){
        if(ans[i] >= maxans){
            maxans = ans[i];
            maxn = i;
        }
        ans[i] = maxn;
    }   
}
int main(){
    IOS 
    int t;
    sieve();
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << ans[n] << '\n';
    }   

    return 0;
}
