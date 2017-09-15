#include <bits/stdc++.h>

using namespace std;

string s;

void init(){
	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	cin >> s;
}

void solve(){
	vector<int> p;
	p.resize(s.size());
	p[0] = 0;
	for (int i = 1; i < s.size(); i++){
		int j = p[i - 1];
		while (j != 0 && s[j] != s[i]) {
			j = p[j - 1];

		}
		if (s[i] == s[j]) j++;
		p[i] = j;
	}
	for (int i = 0; i < s.size(); i++){
		cout << p[i] << " ";
	}
	cout << "\n";
}

int main(){
	init();
	solve();
	return 0;
}
