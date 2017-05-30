#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int n;
vector<int> a;
vector<int> f;

void Init(){
	cin >> n;
	a.resize(n);
	for (int i = 0;i<n;i++){
		cin >> a[i];
	}
	f.resize(n);
}

void Solution(){
	f[0] = 1;
	for (int i = 1;i<n;i++){
		int ch = 0;
		for (int j = i-1;j>=0;j--){
			if (a[j]<a[i]){
				ch = f[j];
				break;
			}
		}
		if (ch) f[i] = ch+1;
		else f[i] = 1;
	}
	int ans = 0;
	for (int i = 0;i<n;i++){
		ans = max(ans,f[i]);
	}
	cout << ans << endl;
}

int main(){
	Init();
	Solution();
	return 0;
}
