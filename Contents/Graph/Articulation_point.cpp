#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector< vector<int> > edge;
vector<int> dfn, low;
int result, dep;

void dfs(int cur, int par)
{
	bool cut = false;
	int child = 0;
	dfn[cur] = low[cur] = ++dep;

	for (auto& i : edge[cur]) {

		if (!dfn[i]) {
			++child;
			dfs(i, cur);
			low[cur] = min(low[cur], low[i]);
			if (low[i] >= dfn[cur]) cut = true;
		}
		else if (i != par) low[cur] = min(low[cur], dfn[i]);
	}

	if ((child >= 2 || par != -1) && cut) ++result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;	
	while (cin >> N && N) {

		cin.ignore();
		result = 0, dep = 0;
		edge.assign(N + 1, vector<int>());
		dfn.assign(N + 1, 0);
		low.assign(N + 1, 0);

		string str;
		while (getline(cin, str)) {

			stringstream ss(str);
			int u, v;
			
			ss >> u;
			if (!u) break;
			while (ss >> v) edge[v].emplace_back(u), edge[u].emplace_back(v);
		}

		dfs(1, -1);

		cout << result << "\n";
	}

	return 0;
}