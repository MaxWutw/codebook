#define MAXN 100005

stack<int> stk;               //stack
vector<int> Graph[MAXN];      //graph
vector<int> Rev_Graph[MAXN];  //reverse graph
bool vis[MAXN];               //is visited
int scc[MAXN];                //i's scc 
int sccid;                    //scc number

void dfs1(int now){
	vis[now]=true;
	for(auto i:Graph[now]){
		if(!vis[i]) dfs1(i);
	}
	stk.push(now);  //push now in stack before return
}

void dfs2(int now){
	vis[now]=true;
	scc[now]=sccid;  //conbine to scc
	for(auto i:Rev_Graph[now]){
		if(!vis[i]) dfs2(i);
	}
}

int main(){
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;
		Graph[u].push_back(v);
		Rev_Graph[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]) dfs1(i); //do dfs1 of all elements
	}
	memset(vis,0,sizeof(vis)); //reset vis array
	while(!stk.empty()){  //iterate all elements of stack
		int x=stk.top();stk.pop();
		if(vis[x]) continue; //skip node which has been combined to another scc
		sccid++;
		dfs2(x);
	}
}