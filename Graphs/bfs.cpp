
#include <bits/stdc++.h>
using namespace std;

void recdfs(vector<int>g[], int s, bool visited[], vector<int> &res){
	res.push_back(s);
	visited[s] = 1;
	for(auto i: g[s]){
		if(!visited[i]){
			recdfs(g, i, visited, res);
		}
	}
}

vector<int> dfs(vector<int> g[], int n){
	bool visited[n];
	memset(visited, 0, sizeof(visited));
	vector<int> res;
	recdfs(g, 0, visited, res);
	return res;
}


int main(){
	int t; cin >> t; while(t--){
		int n,w; cin >> n >> w;
		vector<int> adj[n];
		int u,v;
		for(int i = 0; i< w; i++){
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		vector<int> res = dfs(adj, n);
		for(auto i:res){
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}

