#include <bits/stdc++.h>

using namespace std;


int n, m, timer = 0;
vector<vector<int> > a;
vector<int> tin, fup;
vector<bool> f1, f2;
map<int, bool> help;

inline void init(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	a.resize(n);
	tin.resize(n);
	fup.resize(n);
	f1.resize(n);
	f2.resize(n);
	for (int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		x--, y--;
		a[x].push_back(y);
		a[y].push_back(x);
	}
}

inline void addPoint(int v){
	help[v] = 1;
}

void dfs1(int v, int p){
	f1[v] = 1;
	tin[v] = fup[v] = ++timer;
	for (int i = 0; i < a[v].size(); i++){
		int to = a[v][i];
		if (to == p) continue;
		if (f1[to]) {
			fup[v] = min(fup[v], tin[to]);
		}
		else{
			dfs1(to, v);
			fup[v] = min(fup[v], fup[to]);
			if (fup[to] >= tin[v]){
				addPoint(v);
			}
		}
	}
}

int cnt = 0;
bool ff = 0;

void dfs2(int v, int y){
	f2[v] = 1;
	if (v == y) {
		ff = 1;
		return;
	}
	for (int i = 0; i < a[v].size(); i++){
		if (!f2[a[v][i]]){
			if (a[v][i] != y && help[a[v][i]]) cnt++;
			dfs2(a[v][i], y);
			if (ff) return;
		}
	}
}

inline int getAns(int x, int y){
	cnt = 0;
	ff = 0;
	fill(f2.begin(), f2.end(), 0);
	dfs2(x, y);
	return cnt;
}

void solve(){
	for (int i = 0;i < n; i++){
		if (!f1[i]){
			dfs1(i, i);
		}
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++){
		int x, y;
		cin >> x >> y;
		x--, y--;
		cout << getAns(x, y) << "\n";
	}
}

int main(){
	init();
	solve();
	return 0;
}
