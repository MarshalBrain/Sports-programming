#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> a;

int getDsu(int v){
	return (v == a[v]) ? (v) : (a[v] = getDsu(a[v]));
}

void unionDsu(int v1, int v2){
	v1 = getDsu(v1);
	v2 = getDsu(v2);
	if (rand()%2 & 1){
		a[v1] = v2;
	}
	else{
		a[v2] = v1;
	}
}

void init(){
	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++){
		a[i] = i;
	}
}

void solve(){
	cin >> m;
	for (int i = 0; i < m; i++){
		string type;
		cin >> type;		
		if (type == "?"){
			int v;
			cin >> v;
			v--;
			cout << getDsu(v) + 1 << "\n";
		}
		else{
			int v1, v2;
			cin >> v1 >> v2;
			v1 --, v2 --;
			unionDsu(v1, v2);
			cout << "OK\n";
		}
	}
}

int main(){
	init();
	solve();
	return 0;
}
