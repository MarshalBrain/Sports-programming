#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<long long> a, t;

void build(int v, int tl, int tr){
	if (tl == tr){
		t[v] = a[tl];
		return;
	}
	int tm = (tl + tr) / 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	t[v] =  t[v * 2 + 1] + t[v * 2];
}

void init(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	a.resize(n + 1);
	t.resize(n * 4 + 4);
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	build(1, 1, n);
}

void update(int v, int tl, int tr, int x, int val){
	if (tl == tr){
		t[v] = val;
	}
	else{
		int tm = (tl + tr) / 2;
		if (x <= tm){
			update(v * 2, tl, tm, x, val);
		}
		if (x > tm) {
			update(v * 2 + 1, tm + 1, tr, x ,val);
		}
		t[v] = t[v * 2] + t[v * 2 + 1];
	}
}

int getSum(int v, int tl, int tr, int l, int r){
	if (l > r){
		return 0;
	}
	if (tl == l && tr == r){
		return t[v];
	}
	int tm = (tl + tr) / 2;
	return getSum(v * 2, tl, tm, l, min(r, tm)) + getSum(v * 2  + 1, tm + 1, tr, max(l, tm + 1), r);
} 
 
void solve(){
	cin >> m;
	for (int i = 1; i <= m; i++){
		string type;
		cin >> type;
		if (type == "update"){
			int x, val;
			cin >> x >> val;
			update(1, 1, n, x, val);
			cout << "OK\n";
		}
		if (type == "getsum"){
			int l, r;
			cin >> l >> r;
			cout << getSum(1, 1, n, l, r) << "\n";
		}
	}
}

int main(){
	init();
	solve();
	return 0;
}
