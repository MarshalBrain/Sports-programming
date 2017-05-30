#include <bits/stdc++.h>

using namespace std;


int n;
long long sum = 0;
vector<int> a;

void init(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	a.resize(n+1);
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
		sum += a[i];
	}
}

void solve(){	
	vector<int> f(n+2,0);
	f[0] = 0;
	f[1] = a[1];
	for (int i = 2; i <= n; i++){
		f[i] = max(f[i-1], f[i-2] + a[i]);
	}
	if (f[n] == sum - f[n]) {
		cout << 0 << "\n";
		return;
	}
	for (int i = 1; i <= n; i++){
		cout << f[i] << " ";
	}
	cout << "\n";
/*	if (f[n] > sum - f[n]) 	{
		cout << 1 << "\n";
		return;
	}
	else{
		cout << 2 << "\n";
		return;
	}*/
}

int main(){
	init();
	solve();
	return 0;
}
