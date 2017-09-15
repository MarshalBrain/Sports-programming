#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;
vector<pair<long long, int> > t;

void push(int v){
	if (t[v].second != -1){
		t[v * 2].second = t[v * 2 + 1].second = t[v].second;
		t[v].second = -1;
	}
}

void build(int v, int tl, int tr){
	if (tl == tr){
		t[v].second = t[v].first = a[tl];	
		return;
	}
	int tm = (tl + tr) / 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	t[v].first = t[v * 2].first + t[v * 2 + 1].first;
}

long long getSum(int v, int tl, int tr, int l, int r){
	if (l > r){
		return 0;
	}
	if (l == tl && r == tr){
		return t[v].first;
	}
	int tm = (tl + tr) / 2;
	push(v);
	return getSum(v * 2, tl, tm, l, min(r, tm)) + getSum(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
}

void update(int v, int tl ,int tr, int l, int r, int val){
	if (l > r){
		return;
	}
	if (l == tl && r  == tr){
		t[v].second = val;
		t[v].first = val * (tr - tl + 1);
		return;
	}
	push(v);
	int tm = (tl + tr) / 2;
	update(v * 2, tl, tm, l, min(r, tm), val);
	update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
	t[v].first = t[v * 2].first + t[v * 2 + 1].first;
}
	
void init(){
	cin >> n;
	a.resize(n);
	t.resize(n*4);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	build(1,0,n-1);
}

void solve(){
	int m;
	cin >> m;
	for (int i = 0; i < m; i ++){
		int type;
		cin >> type;
		if (type == 1){
			int l, r;
			cin >> l >> r;
			l --, r --;
			cout << getSum(1,0,n-1,l,r) << "\n";
		}
		else{
			int l , r, val;
			cin >> l >> r >> val;
			l--, r--;
			update(1,0,n-1,l,r,val);
			cout << "OK\n";
		}
	}
}			

int main(){
	init();
	solve();
	return 0;
}
