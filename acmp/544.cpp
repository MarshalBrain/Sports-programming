#include <iostream>
#include <vector>

using namespace std;

int n;

void Init(){
	cin >> n;
}

void Solution(){
	vector<long long> f(n+1,0);
	f[n-1] = 1;
	if (n>1) f[n-2] = 1;
	if (n>2) f[n-3] = 1;
	for (int i = n-1;i>0;i--){
		if (i>0) f[i-1]+=f[i];
		if (i>1) f[i-2]+=f[i];
		if (i>2) f[i-3]+=f[i];
	}
	cout << f[0] << endl;
}
	
int main(){
	Init();
	Solution();
	return 0;
}
