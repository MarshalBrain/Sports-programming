#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm> 

using namespace std;

int n;
vector<pair<int, int> > a;

void Init(){
	cin >> n;
	a.resize(n+1);
	for (int i = 0;i<n;i++){
		int age,val;
		cin >> age >> val;
		a[i] = make_pair(age,val);
	}
}

void Soltion(){
	vector<int> f;
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	f.resize(n+1);
	f[1] = a[0].second;
	f[2] = a[1].second+f[1];
	for (int i = 3;i<n;i++){
		f[i] = min(f[i-1]+a[i-1].second,f[i-2]+a[i-1].second);
	}
	cout << f[n-1];
}

int main(){
	Init();
	Soltion();
	return 0;
}
