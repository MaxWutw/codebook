#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int dp[205][2];
bool uni[205][2];
void dfs(vector<int> vec[205], int u){
    dp[u][0] = 0;
    dp[u][1] = 1;
    uni[u][0] = 1;
    uni[u][1] = 1;
    for(auto v : vec[u]){
        dfs(vec, v);
        dp[u][1] += dp[v][0];
        dp[u][0] += max(dp[v][0], dp[v][1]);
        if(dp[v][0] > dp[v][1]){
            if(!uni[v][0]) uni[u][0] = 0;
        }
        else if(dp[v][1] > dp[v][0]){
            if(!uni[v][1]) uni[u][0] = 0;
        }
        if(dp[v][0] == dp[v][1]) uni[u][0] = 0;
        if(!uni[v][0]) uni[u][1] = 0;
    }
}
int main(){
    IOS
    int n;
    while(cin >> n && n){
        unordered_map<string, int> un;
        vector<int> vec[205];
        string boss;
        cin >> boss;
        int idx = 0;
        un[boss] = idx++;
        memset(uni, 1, sizeof(uni));
        memset(dp, 0, sizeof(dp));
        for(int i = 0;i < n - 1;i++){
            string str1, str2;
            cin >> str1 >> str2;
            if(!un[str1]) un[str1] = idx++;
            if(!un[str2]) un[str2] = idx++;
            vec[un[str2]].push_back(un[str1]);
        }
        dfs(vec, un[boss]);
        cout << max(dp[un[boss]][0], dp[un[boss]][1]) << ' ';
        if(dp[un[boss]][0] == dp[un[boss]][1]){
            cout << "No" << '\n';
        }
        else if(dp[un[boss]][0] > dp[un[boss]][1]){
            cout << (uni[un[boss]][0] ? "Yes" : "No") << '\n';
        }
        else if(dp[un[boss]][1] > dp[un[boss]][0]){
            cout << (uni[un[boss]][1] ? "Yes" : "No") << '\n';
        }
    }

    return 0;
}