#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int n,k;
vector<vector<long long> > dp;
void read(){
	scanf("%d%d",&n,&k);
	dp.resize(n+1);
	for (int i = 1;i<=n;i++){
		dp[i].resize(k);
	}
}
void solution(){
	for (int i = 1;i<k;i++){
		dp[1][i] = 1;
	}
	for (int i = 2;i<=n;i++){
		for (int j = 0;j<k;j++){
			if (j == 0){
				for (int l = 1;l<k;l++){
					dp[i][j]+=dp[i-1][l];
				}
			}	
			else {
				for (int l = 0;l<k;l++){
					dp[i][j]+=dp[i-1][l];
				}
			}
		}
	}
	long long ans = 0;
	for (int i = 0;i<k;i++){
		ans+=dp[n][i];
	}
	cout << ans << endl;
} 
int main(){
	read();
	solution();
	return 0;
}
