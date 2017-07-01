#include <iostream>
#include <vector>
#include <utility>
#define ll long long
using namespace std;

const ll INF = 1e9+7;

ll m,maxi = 0;
vector<ll> a;
vector<pair<ll,ll> > t;
vector<pair<int, int> > z;
void build(ll v, ll tl, ll tr){
	if (tl == tr){
		t[v] = make_pair(a[tl],a[tl]);
		return;
	}
	ll tm = (tl+tr)/2;
	build(v*2,tl,tm);
	build(v*2+1,tm+1,tr);
	t[v] = make_pair(max(t[v*2].first, t[v*2+1].first),min(t[v*2].second,t[v*2+1].second));
}
pair<ll, ll> get_ans(ll v, ll tl, ll tr, ll l, ll r){
	if (l>r){
		return make_pair(-INF,INF);
	}
	if (tl == l && tr == r){
		return t[v];
	}
	ll tm = (tl+tr)/2;
	pair<ll, ll> val1 = get_ans(v*2,tl,tm,l,min(tm,r)), val2 = get_ans(v*2+1,tm+1,tr,max(tm+1,l),r);
	return make_pair(max(val1.first, val2.first),min(val1.second, val2.second));
}
void update(ll v, ll tl, ll tr, ll x, ll new_val){
	if (tl == tr){
		t[v] = make_pair(new_val,new_val);
		return;
	}
	ll tm = (tl+tr)/2;
	if (x<=tm){
		update(v*2,tl,tm,x,new_val);
	}
	else {
		update(v*2+1,tm+1,tr,x,new_val);
	}
	t[v] = make_pair(max(t[v*2].first,t[v*2+1].first),min(t[v*2].second,t[v*2+1].second));
}	
void read(){
	scanf("%d",&m);
	z.resize(m+1);
	for (int i = 0;i<m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		z[i] = make_pair(x,y);
		if (x<0){
			if (-x>maxi) maxi = x;
		}
		else{
			maxi = max(maxi,(ll)max(x,y));
		}
	}
	a.resize(maxi+1);
	t.resize(maxi*4+1);
	for (ll i = 0;i<maxi;i++){
		int j = i+1;
		a[i] = (j*j)%12345+(j*j*j)%23456;
	}
	build(1,0,maxi-1);
}
void solution(){
	for (ll i = 0;i<m;i++){
		ll x,y;
		x = z[i].first, y = z[i].second;
		if (x<0) {
			x=-x;
			x--;
			update(1,0,maxi-1,x,y);
		}
		else{
			x--,y--;
			pair<ll, ll> ans = get_ans(1,0,maxi-1,x,y);
			cout << ans.first-ans.second << endl;	
		}
	}	
}
int main(){
	read();
	solution();
	return 0;
}
