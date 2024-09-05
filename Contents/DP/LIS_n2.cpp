#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
    IOS
    int arr[100];
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) cin >> arr[i];
    int dp[100];
    for(int i = 0;i < n;i++) dp[i] = 1;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < i;j++){
            if(arr[i] > arr[j])
                dp[i] = max(dp[j] + 1, dp[i]);
        }
    }
    int ans = 1;
    for(int i = 0;i < n;i++) ans = max(ans, dp[i]);
    cout << ans << '\n';

    return 0;
}