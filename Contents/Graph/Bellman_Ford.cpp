#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
struct Edge{
	int x, y, t;
};
int dis[1005];
int main(){
	IOS
	int c;
	cin >> c;
	while(c--){
		vector<Edge> edge;
		int n, m;
		cin >> n >> m;
		for(int i = 0;i <= n;i++) dis[i] = INF;
		dis[0] = 0;
		for(int i = 0;i < m;i++){
			int x, y, t;
			cin >> x >> y >> t;
			edge.push_back({x, y, t});
		}
		for(int i = 0;i < n - 1;i++){
			for(int j = 0;j < m;j++){
				if(dis[edge[j].x] + edge[j].t < dis[edge[j].y]){
					dis[edge[j].y] = dis[edge[j].x] + edge[j].t;
				}
			}
		}
		bool judge = true;
		for(auto e : edge){
			if(dis[e.x] + e.t < dis[e.y]){
				judge = false;
				break;
			}
		}
		cout << (judge ? "not possible" : "possible") << '\n';
	}

	return 0;
}