#include <bits/stdc++.h>

using namespace std;

int n, m, timer = 0;
vector<vector<int> > a;
vector<bool> f;
vector<pair<int, int> > ans;
vector<int> tin, fup;

void init(){
	cin >> n >> m;
	a.resize(n);
	tin.resize(n);
	fup.resize(n);
	f.resize(n);
	for (int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		x--, y--;
		a[x].push_back(y);
		a[y].push_back(x);
	}
}

void dfs(int v, int p){
	f[v] = 1;
	tin[v] = fup[v] = ++timer;
	for (int i = 0; i < a[v].size(); i++){
		int to = a[v][i];
		if (to == p) continue;
		if (f[to]){
			fup[v] = min(fup[v], tin[to]);
		}
		else{
			dfs(to, v);
			fup[v] = min(fup[v], fup[to]);
			if (fup[to] > tin[v]) ans.push_back(make_pair(v, to));
		}
	}
}

void solve(){
	for (int i = 0; i < n; i ++){
		if (!f[i]){
			dfs(i, i);
		}
	}
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
	}
}

int main(){
	init();
	solve();
	return 0;
}
