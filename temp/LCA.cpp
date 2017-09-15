#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5+5;
int n, cnt, timer = 0;
vector<vector<int> > a;
vector<int> tin, tout;
int up[maxN][30];

void init(){	
	scanf("%d",&n);
	a.resize(n + 1);
	tin.resize(n + 1);
	tout.resize(n + 1);
	for (int i = 0; i < n - 1; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
}

void dfs(int v, int p){
	tin[v] = ++timer;
	up[v][0] = p;
	for (int i = 1; i <= cnt; i++){
		up[v][i] = up[up[v][i-1]][i-1];
	}
	for (int i = 0; i < a[v].size(); i++){
		if (a[v][i] != p){
			dfs(a[v][i], v);
		}
	}
	tout[v] = ++timer;
}

bool upper(int x, int y){
	return tin[x] <= tin[y] && tout[x] >= tout[y];
}

int LCA(int x, int y){
	if (upper(x,y)) return x;
	if (upper(y,x)) return y;
	for (int i = cnt; i >= 0; i--){
		if (!upper(up[x][i],y)){
			x = up[x][i];
		}
	}
	return up[x][0];
}

void solve(){
	cnt = 0;
	while ((1 << cnt) <= n) cnt++;
	dfs(1,1);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		cout << LCA(x, y)  << "\n";
	}	
}

int main(){
	init();
	solve();
	return 0;
}
