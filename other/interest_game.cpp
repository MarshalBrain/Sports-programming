#include <bits/stdc++.h>

using namespace std;

int n;

void init(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
}

int getLength(){
	int i = 0;
	while (1 << i <= n) i++;
	return i;
}

void solve(){
	long long ch = n >> 1, ans = n;
	int len = getLength();
	if (1 & n) ch += 1 << (len - 1);
	while (ch != n){
	//	cout << ch << endl; 
		ans = max(ans, ch); 
		long long temp = ch >> 1;
		if (1 & ch) temp += 1 << (len - 1);
		ch = temp;
	}
	cout << ans << "\n";
}

void files(){
	freopen("6.in","r",stdin);
//	freopen("output.txt","w",stdout);
}

int main(){
 	files();
	init();
	solve();
	return 0;
}
