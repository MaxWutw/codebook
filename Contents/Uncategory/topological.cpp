//拓鋪
int N, M, u, v, deg[MAXN];    // deg[i] 紀錄點 i 被連入邊數
vector<int> edge[MAXN];

/*------ 1. 計算 indegree ------*/
cin >> N >> M;
while(M--)
{
    cin >> u >> v;
    edge[u].push_back(v);
    ++deg[v];
}

/*------ 2. 將 indegree 為 0 的點放入 queue 中 ------*/
queue<int> q;                // 紀錄待拔點
for(int i = 0; i < N; ++i)
    if(deg[i] == 0)
        q.push(i);

/*------ 3. 重複拔點，直到 queue 清空 ------*/
while(!q.empty())
{
    int cur = q.front();	q.pop();
    cout << cur << "\n";
    for(int i: edge[cur])
    {
        --deg[i];                           // 3-1. 相連點 indgree 減一
        if(deg[i] == 0)	q.push(i);    // 3-2. 若該點 indgree 減至 0，則放入 queue 中
    }
}