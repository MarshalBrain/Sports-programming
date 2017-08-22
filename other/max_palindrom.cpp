#include <bits/stdc++.h>

using namespace std;

int n;
string s;
vector<int> ans;

void init(){
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> s;
	n = s.size();
}

int getAns(int v){
	int l = v-1, r = v+1;
	int ans = 1;
	while (s[l] == s[r]){
		ans += 2;
		l--, r++;
		if (l < 0 || r == n) break;;
	}
	return ans;
}

void solve(){
	ans.resize(n);
	for (int i = 0;i < n; i++){
		ans[i] = getAns(i);
	}
	for (int i = 0; i < n; i++){
		cout << ans[i] << " ";
	}
	cout << "\n";
}

int main(){
	init();
	solve();
	return 0;
}
