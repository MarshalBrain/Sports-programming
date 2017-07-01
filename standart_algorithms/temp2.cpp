#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#define ll long long 

using namespace std;
int n,k,sz = 1;
const int maxN = 5e5+5;
int t[maxN];
int clr[maxN];

void files(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
}

void read(){
	cin >> n >> k;
	while (sz<n){
			sz*=2;
	}
}

void push(int v, int x, int y){
	if (clr[v] != -1){
		clr[v*2] = clr[v*2+1] = clr[v];
		clr[v] = -1;
		t[v*2] = t[v*2+1] = clr[v*2] * 1ll * ((y-x+1)/2);
	}
}

void update(int v, int tl, int tr, int l, int r, int x){
	if (l>r){
		return;
	}
	if (l == tl && r == tr){
		clr[v] = x;
		t[v] = (r-l+1)*1ll*x;
		return;
	}
	int tm = (tl+tr)/2;
	push(v,tl,tr);
	update(v*2,tl,tm,l,min(tm,r),x);
	update(v*2+1,tm+1,tr,max(l,tm+1),r,x);
	t[v] = t[v*2]+t[v*2+1];
}

long long get_sum(int v, int tl, int tr, int l, int r){
	if (l>r){
		return 0;
	}
	if (tl == l && tr == r){
		return t[v];
	}
	int tm = (tl+tr)/2;
	push(v,tl,tr);
	return get_sum(v*2,tl,tm,l,min(r,tm))+get_sum(v*2+1,tm+1,tr,max(l,tm+1),r);
}
		
void solution(){
	for (int i = 0;i<k;i++){
		char type;
		cin >> type;
		if (type == 'A'){
			int l,r,x;
			cin >> l >> r >> x;
			update(1,1,sz,l,r,x);
		}
		else{
			int l,r;
			cin >> l >> r;
			cout << get_sum(1,1,sz,l,r) << endl;
		}
	}
}

int main(){
	files();
	read();
	solution();
	return 0;
}
