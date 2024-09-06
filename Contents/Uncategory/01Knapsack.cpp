// 01 backpack
for(int i=1;i<=n;i++){
    for(int j=x;j>=w[i];j--){
        dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
    }
}