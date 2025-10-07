//n為會跑到的最大值
bool isprime[1000005]; //紀錄每個數字是否是質數
vector<int> prime; // 儲存範圍內所有的質數
isprime[1]=1; // 1 代表此數字不是質數，否則為 0
//先將所有大於1數字設為質數(0)
 
for(int i=2;i<=n;i++){
    if(!isprime[i]){    //如果為質數
        prime.push_back(i);
        for(long long j=2;i*j<=n;j++){ //記得容易會爆int的話要設long long
            //所有質數的倍數設成非質數
            isprime[i*j] = 1;
        }
    }
}
