#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

int n;
vector<int> a;
vector<int> f;

void Init(){
	cin >> n;
	a.resize(n);
	f.resize(n);
	for (int i = 0;i<n;i++){
		cin >> a[i];
	}
	f[0] = 0;
}

void Solution(){
	f[1] = abs(a[1]-a[0]);
	for (int i = 2;i<n;i++){
		f[i] = min(abs(a[i-1]-a[i])+f[i-1],3*abs(a[i-2]-a[i])+f[i-2]);
	}
	cout << f[n-1] << endl;
}

int main(){
	Init();
	Solution();
	return 0;
}
