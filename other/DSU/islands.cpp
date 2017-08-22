#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
using namespace std;
vector<pair<int, int> > a;
vector<int> ranc;
vector<int> dsu;
int n,m,kol;
void read(){
	scanf("%d%d",&n,&m);
	for (int i = 0;i<n;i++){
		dsu.push_back(i);
		ranc.push_back(1);
	}
	kol = n;
}
int get(int v){
	if (v == dsu[v]) return v;
	dsu[v] = get(dsu[v]);
}
void union_dsu(int a, int b){
	a = get(a);
	b = get(b);
	if (ranc[a]>ranc[b]){
		swap(a,b);
	}
	if (ranc[a] == ranc[b]){
		ranc[b]+=ranc[a];
	}
	dsu[a] = b;
}
void solution(){
	bool f = 0;
	long long ans = 0;
	for (int i = 0;i<m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if (f == 1) continue;
		x--,y--;
		if (get(x) == get(y)) continue;
		else{
			union_dsu(x,y);
			kol--;
		}
		if (kol == 1) {ans = i+1;f = 1;continue;}
	} 		
	cout << ans;
}
int main(){
	read();
	solution();
	return 0;
}