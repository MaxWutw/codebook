#define mem(x) memset(x, 0, sizeof(x))
struct road{
	int r, val;
};
int main(){
	int n, e, l, r, v;
	cin >> n >> e;
	vector<int> dp(n + 1, 1e9);
	vector<road> rd[n + 1];
	for(int i = 0; i < e; i++){
		cin >> l >> r >> v;
		rd[l].push_back({r, v});
		rd[r].push_back({l, v});
	}
	cin >> l >> r;
	dp[l] = 0;
	queue<int> que;
	que.push(l);
	bool check[n + 1]; mem(check);
	int cnt[n + 1]; mem(cnt);
	while(!que.empty()){
		int tmp = que.front(); que.pop();
		check[tmp] = 0, cnt[tmp]++;
		if(cnt[tmp] >= n) {cout << "neg cycle\n"; break;}
		for(auto & i : rd[tmp]){
			if(dp[i.r] > dp[tmp] + i.val){
				dp[i.r] = dp[tmp] + i.val;
				if(!check[i.r]) check[i.r] = 1, que.push(i.r);
			}
		}
	}
	for(auto & i : dp) cout << i << ' ';
	return 0;
}