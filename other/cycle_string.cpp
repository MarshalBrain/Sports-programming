#include <bits/stdc++.h>

using namespace std;

string s;
int n;
vector<int> pr;

void init(){
	cin >> s;
}

void make_pref(){
	pr.clear();
	n = s.size();
	pr.resize(n);
	pr[0] = 0;
	for (int i = 1;i < n; i++){
		int j = pr[i-1];
		while (j > 0 && s[i] != s[j]) j = pr[j-1];
		if (s[i] == s[j]) j++;
		pr[i] = j;
	}
}
	
void solve(){
	make_pref();
	int val = 0;
	for (int i = 0;i < n; i++){
		val = max(val, pr[i]);
	}
	cout << pr[n-1] << "\n";
}

int main(){
	init();
	solve();
	return 0;
}
