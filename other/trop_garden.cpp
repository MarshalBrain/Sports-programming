#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<double, double> > a;

void init(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	a.resize(n+1);
	for (int i = 1; i <= n; i++){
		double x, y;
		cin >> x >> y;
		a[i] = make_pair(x,y);
	}
}

double getDist(double x1, double y1, double x2, double y2){
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void solve(){
	double x = 1.0, y = 1.0, p = 1.0;
	int it = 0, cnt = 1e5 + 103;
	while (it <= cnt){
		double maxDist = 0, xd = 0, yd = 0;
		for (int i = 1; i <= n; i++){
			double val = getDist(a[i].first, a[i].second, x, y);
			if (val > maxDist){
				maxDist = val;
				xd = a[i].first;
				yd = a[i].second;
			}
		}
		x = x + (xd - x) * p;
		y = y + (yd - y) * p;
		p *= 0.997;
		it++;
	}
	double R = 0;
	for (int i = 1; i <= n; i++){
		R = max(R, getDist(a[i].first, a[i].second, x, y));
	}
	cout << fixed << setprecision(11); 
	cout << R << "\n";
	cout << x << "\n" << y << "\n";
}

void files(){
	freopen("10.IN", "r", stdin);
}
			
int main(){
	files();
	init();
	solve();
	return 0;
}
