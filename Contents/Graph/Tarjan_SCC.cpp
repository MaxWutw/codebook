#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

map<string, vector<string>> G;
map<string, int> dfn, low;
vector<string> V;
int dep;

void dfs(string u)
{
    low[u] = dfn[u] = ++dep;
    V.emplace_back(u);

    for (auto& v : G[u])
        if (!dfn[v]) dfs(v), low[u] = min(low[u], low[v]);
        else if (count(V.begin(), V.end(), v)) low[u] = min(low[u], dfn[v]);
    
    if (dfn[u] == low[u])
    {
        string temp;
        while (1)
        {
            temp = V[V.size() - 1];
            V.pop_back();
            cout << temp;
            if (temp != u) cout << ", ";
            else break;
        }
        cout << "\n";
    }
}

int main()
{
    // fast io
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, cases = 0;
    while (cin >> n >> m, n && m) 
    {
        // init
        G.clear(), dfn.clear(), low.clear(), V.clear();
        dep = 0;

        // store data
        while (m--)
        {
            string name, to;
            cin >> name >> to;
            G[name].emplace_back(to);
        }

        // find scc
        if (cases) cout << "\n";
        cout << "Calling circles for data set " << ++cases << ":\n";
        for (auto& [i, j] : G) if (!dfn[i]) dfs(i);	
    }

    return 0;
}
