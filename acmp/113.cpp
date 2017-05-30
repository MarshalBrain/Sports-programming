#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e3+4;
int n;
int a[maxN][maxN], UpDown[maxN][maxN], LeftRight[maxN][maxN];

void init(){
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			char ch;
			cin >> ch;
			if (ch == '1') a[i][j] = 1;
			else a[i][j] = 0;
		}
	}
}

void calculate(){
	for (int i = 1; i <= n; i ++){
		for (int j = 1; j <= n; j++){
			if (a[i][j] == 0){
				UpDown[i][j] = 0;
				LeftRight[i][j] = 0;
			}
			else{
				UpDown[i][j] = UpDown[i-1][j] + 1;
				LeftRight[i][j] = LeftRight[i][j-1] + 1;
			}
		}
	}
}

void solve(){
	calculate();
	int ans = 0;
	int f[maxN][maxN];
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (a[i][j] == 0){
				f[i][j] = 0;
			}
			else{
				f[i][j] = min(f[i-1][j-1] + 1, min(UpDown[i][j], LeftRight[i][j]));
			}
			ans = max(ans, f[i][j]);
		}
	}
	cout << ans*ans << "\n";
}
				
int main(){
	init();
	solve();
	return 0;
}
