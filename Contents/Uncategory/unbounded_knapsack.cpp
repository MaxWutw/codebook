//無限背包

for(int i=1;i<=W;i++){ // 從小到大遍歷重量
    for(int j=1;j<=n;j++){ // 遍歷每個物品
        if(i>=w[j]) dp[i]=max(dp[i],dp[i-w[j]]+v[j]);
    }
}