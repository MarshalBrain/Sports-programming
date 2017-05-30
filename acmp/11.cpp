#include <iostream>
#include <vector>

using namespace std;

int n,k;
vector<vector<int>> f;

vector<int> sum(vector<int> a, vector<int> b){
	int ost = 0;
	for (int i = 0;i<max(a.size(),b.size()) || ost;i++){
		if (i == a.size()) a.push_back(0);
		a[i]+=(i<b.size() ? b[i] : (int)0) + ost;
		ost = a[i]/10;
		a[i]%=10;
	}
	return a;
}

void Init(){
	cin >> k >> n;
	f.resize(n+3);
}

void Solution(){
	for (int i = 1;i<=k;i++){
		f[i].push_back(1);
	}
	for (int i = 1;i<=n;i++){
		for (int j = 1;i+j<=n && j<=k;j++){
			f[i+j] = sum(f[i],f[i+j]);
			 
		}
	}
	for (int i = f[n].size()-1;i>=0;i--) cout << f[n][i];
	cout << endl;
}

int main(){
	Init();
	Solution();
	return 0;
}

