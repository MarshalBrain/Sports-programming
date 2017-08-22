#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e3+5;
int n, W;
vector<pair<int, int> > a;

void init(){
	cin >> n >> W;
	a.resize(n+1);
	for (int i = 1; i <= n; i++){
		int weight, price;
		cin >> weight >> price;
		a[i] = make_pair(weight, price);
	}
}

void solve(){
	int f[maxN][maxN];
	
	for (int i = 0; i <= n ;i++){
		f[i][0] = 0;
	}
	for (int i = 0; i <= W; i ++){
		f[0][i] = 0;
	}
	for (int k = 1; k <= n; k++){
		for (int s = 1; s <= W; s++){
			if (a[k].first <= s){
				f[k][s] = max(f[k-1][s], f[k-1][s-a[k].first] + a[k].second);
			}
			else{
				f[k][s] = f[k-1][s];
			}
		}
	}
	cout << f[n][W] << "\n";
}
		
int main(){
	init();
	solve();
	return 0;
}
