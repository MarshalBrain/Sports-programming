#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define pb push_back

using namespace std;
int dp[5000];
int main()
{
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    dp[0] = 0;
    for (int i = 1;i<=n;i++) dp[i] = -1;
    for (int i = 1;i<=n;i++)
    {
        if (i-a>=0) dp[i]=max(dp[i-a],dp[i]);
        if (i-b>=0) dp[i]=max(dp[i-b],dp[i]);
        if (i-c>=0) dp[i]=max(dp[i-c],dp[i]);
        if (dp[i]!= -1) dp[i]++;
    }
    cout << dp[n];
    return 0;
}
