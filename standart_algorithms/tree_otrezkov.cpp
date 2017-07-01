#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
int n,m;
vector<int> a;
vector<int> t;
void build(int v, int tl, int tr){
	if (tl == tr){
		t[v] = a[tl];
	}
	else{
		int tm = (tl+tr)/2;
		build(v*2,tl,tm);
		build(v*2+1,tm+1,tr);
		t[v] = t[v*2]+t[v*2+1];
	}
}
long long sum(int v, int tl, int tr, int l, int r){
	if (l> tr || r<tl){
		return 0;
	}
	if (l <= tl && r >= tr) return t[v];
	int tm = (tl+tr)/2;
	return sum(v*2,tl,tm,l,r)+sum(v*2+1,tm+1,tr,l,r);
}
/*void update(int v, int tl, int tr, int x, int new_val){
	if (tl == tr){
		t[v] = new_val;
		return;
	}
	int tm = (tl+tr)/2;
	if (x<=tm){
		update(v*2,tl,tm,x,new_val);
	}
	else{
		update(v*2+1,tm+1,tr,x,new_val);
	}
	t[v] = t[v*2]+t[v*2+1];
}*/	
void read(){
	scanf("%d",&n);
	a.resize(n+1);
	t.resize(4*n+1);
	for (int i = 1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	scanf("%d",&m);
}
void files(){
	freopen("sum2.in","r",stdin);
	freopen("sum2.out","w",stdout);
}
void solution(){
	for (int i = 0;i<m;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		cout << sum(1,1,n,l,r) << endl;
	}
}	
int main(){
	files();
	read();
	solution();
	return 0;
}
