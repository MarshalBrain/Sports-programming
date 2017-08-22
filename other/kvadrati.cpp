#include <bits/stdc++.h>

using namespace std;

int n;

void init(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
}

void solve(){
	int ans = 1e9;
	if (round(sqrt(n)) * round(sqrt(n)) == n){
		cout << 1 << "\n";
		return;
	}
	for (int i = 0; i <= round(sqrt(n)); i++){
		for (int j = 0; j <= round(sqrt(n-i)); j++){
			for (int l = 0; l <= round(sqrt(i-j)); l++){
				if (i*i + j*j + l*l == n){
					if (i == 0 || j == 0 || l == 0){
						cout << 2 << "\n";
						return;
					}
					else{
						ans = 3;
					}
				}
			}
		}
	}
	if (ans == 1e9) {
		cout << 4 << "\n";
	}
	else{
		cout << ans << "\n";
	}
}
	 
int main(){
	init();
	solve();
	return 0;
}
