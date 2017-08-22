#include <cstdio>
#include <iostream>
#include <limits>
#include <vector>
 
using namespace std;
 
const int MAXN = 300 + 10;
const int INF = numeric_limits <int>::max();
 
int a[MAXN][MAXN], dp[MAXN * 2][MAXN][MAXN];
 
void solve(){
    int n, m;
    scanf("%d", &n);
    m = n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
 
    for (int i = 1; i <= n + m; i++)
        for (int j = 1; j <= n; j++)
            for (int d = 1; d <= n; d++)
                dp[i][j][d] = -INF;
 
    dp[1][1][1] = a[1][1];
    for (int diag = 1; diag < n + m - 1; diag++){
        for (int first = 1; first <= n; first++)
            for (int second = 1; second <= n; second++){
                if (dp[diag][first][second] == -INF) continue;
                if (diag - first + 1 > n || diag - second + 1 > n) continue;
                if (first == second){
                    dp[diag + 1][first][second] = max(dp[diag + 1][first][second], dp[diag][first][second] + a[first][diag - first + 2]);
                    dp[diag + 1][first + 1][second + 1] = max(dp[diag + 1][first + 1][second + 1], dp[diag][first][second] + a[first + 1][diag - first + 1]);
                }
                else {
                    dp[diag + 1][first][second] = max(dp[diag + 1][first][second], dp[diag][first][second] + a[first][diag - first + 2] + a[second][diag - second + 2]);
                    dp[diag + 1][first + 1][second + 1] = max(dp[diag + 1][first + 1][second + 1], dp[diag][first][second] + a[first + 1][diag - first + 1] + a[second + 1][diag - second + 1]);
                }
                if (first + 1 == second){
                    dp[diag + 1][first + 1][second] = max(dp[diag + 1][first + 1][second], dp[diag][first][second] + a[first + 1][diag - first + 1]);
                }
                else {
                    dp[diag + 1][first + 1][second] = max(dp[diag + 1][first + 1][second], dp[diag][first][second] + a[first + 1][diag - first + 1] + a[second][diag - second + 2]);
                }
                if (first == second + 1){
                    dp[diag + 1][first][second + 1] = max(dp[diag + 1][first][second + 1], dp[diag][first][second] + a[first][diag - first + 2]);
                }
                else {
                    dp[diag + 1][first][second + 1] = max(dp[diag + 1][first][second + 1], dp[diag][first][second] + a[first][diag - first + 2] + a[second + 1][diag - second + 1]);
                }
            }
    }
 
    printf("%d", dp[n + m - 1][n][n]);
}
 
int main(){
 
    solve();
 
    return 0;
}