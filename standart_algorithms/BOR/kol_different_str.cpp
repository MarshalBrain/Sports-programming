#include <bits/stdc++.h>

using namespace std;
 
int a[(int)1e4+100][30];
int n, ans = 0, cnt = 0;
string s;

void init(){
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> s;
	n = s.size();
}

inline void build(int l, int r){
	int j = 0;
	for (int i = l; i < r; i ++){
		int sim = (int)s[i] - 'a';
		if (a[j][sim] != 0) j = a[j][sim];
		else{
			a[j][sim] = ++cnt;
			j = cnt;
		}
	}
}

void getAns(int v){
	for (int i = 0; i < 26; i++){
		if (a[v][i] != 0) {
			ans++;
			getAns(a[v][i]);
		}
	}
}

void solve(){
	for (int i = 0;i < n; i++){
		build(i, n);
	}	
	getAns(0);
	cout << ans << "\n";
}

void files(){
	freopen("unequal.in","r",stdin);
	freopen("unequal.out","w",stdout);
}

int main(){
//	files();
	init();
	solve();
	return 0;
}
