#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
int n;
const int INF = 2000000000;
const int maxN = 300+2;
int dp[2*maxN][maxN][maxN],a[maxN][maxN];
void solve(){
	cin >> n;
	for (int i = 1;i<=2*n;i++){
		for (int l = 1;l<=n;l++)
			for (int j = 1;j<=n;j++) dp[i][l][j] = -INF;		 
	}
	for (int i = 1;i<=n;i++){
		for (int j = 1;j<=n;j++){
			cin >> a[i][j];
		}
	}
	dp[1][1][1] = a[1][1];
	for (int i = 1;i<2*n-1;i++)
		for (int c1 = 1;c1<=n;c1++){
			for (int c2 = 1;c2<=n;c2++){
				if (dp[i][c1][c2] == -INF) continue;
				if (i-c2 > n || i-c1>n) continue;
				if (c1 == c2){
					dp[i+1][c1][c2] = max(dp[i+1][c1][c2], dp[i][c1][c2] + a[c1][i-c1+2]);
					dp[i+1][c1+1][c2+1] = max(dp[i+1][c1+1][c2+1], dp[i][c1][c2] + a[c1+1][i-c1+1]);
				}
				else{
					dp[i+1][c1][c2] = max(dp[i+1][c1][c2],dp[i][c1][c2] + a[c1][i-c1+2] + a[c2][i-c2+2]);
					dp[i+1][c1+1][c2+1] = max(dp[i+1][c1+1][c2+1], dp[i][c1][c2]+a[c1+1][i-c1+1] + a[c2+1][i-c2+1]);
				}
				if (c1+1 == c2) {
					dp[i+1][c1+1][c2] = max(dp[i+1][c1+1][c2], dp[i][c1][c2] + a[c1+1][i-c1+1]);						
				}
				else {
					dp[i+1][c1+1][c2] = max(dp[i+1][c1+1][c2], dp[i][c1][c2] + a[c1+1][i-c1+1] + a[c2][i-c2+2]);
				}	
				if (c2+1 == c1){
					dp[i+1][c1][c2+1] = max(dp[i+1][c1][c2+1], dp[i][c1][c2] + a[c2+1][i-c2+1]);
				}
				else{
					dp[i+1][c1][c2+1] = max(dp[i+1][c1][c2+1], dp[i][c1][c2] + a[c2+1][i-c2+1] + a[c1][i-c1+2]);
				}	  
			}
	}
	cout << dp[2*n-1][n][n];
}
int main(){
    solve();
    return 0;
}