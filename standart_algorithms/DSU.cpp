#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;
int n,q;
vector<int> p;
void files(){
	freopen("input.txt","r",stdout);
	freopen("output.txt","w",stdout);
}
void make_set(int v){
	p[v] = v;
}
int find_set(int v){
	if (v == p[v]) return v;
	p[v] = find_set(p[v]);
}
bool union_set(int x,int y){
	x = find_set(x);
	y = find_set(y);
	if (x == y) return true;
	int temp = rand()%1+0;
	if (temp%2 == 0){
		p[x] = y;
	}
	else {
		p[y] = x;
	}
	return false;
}		
void read(){
	scanf("%d",&n);
	p.resize(n);
	for (int i = 0;i<n;i++){
		make_set(i);
	}
}
void solution(){
	scanf("%d",&q);
	for (int i = 0;i<q;i++){
		int type;
		scanf("%d",&type);
		if (type == 0){
			int v;
			scanf("%d",&v);
			v--;
			cout << find_set(v)+1 << endl;
		}
		else{
			int x,y;
			scanf("%d%d",&x,&y);
			x--,y--;
			if (union_set(x,y)) cout << "This acme's are in the one subset" << endl;
			else cout << "OK" << endl;
		}
	}
}
int main(){
//	setlocale(0,"Russian");
//	files();
	read();
	solution();
	return 0;
} 