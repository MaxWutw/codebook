int n, rd, l, r, v;
cin >> n >> rd;
vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e9));
for(int i = 0; i < rd; i++){
    cin >> l >> r >> v;
    dp[l][r] = dp[r][l] = v;
    //每條路皆雙向 
}

//以下即 Floyd-Warshall
for(int k = 1; i <= n; i++){
    for(int i = 1; j <= n; j++){
        for(int j = 1; k <= n; k++){
            dp[i][j] = min(dp[i][k] + dp[k][j] , dp[i][j]);
            //窮舉所有鬆弛可能
        }
    }
}
cin >> l >> r;
cout << dp[l][r];