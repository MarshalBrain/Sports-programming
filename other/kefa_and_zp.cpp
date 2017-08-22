#include <iostream>
#include <cmath>
#include <vector>
#define pb push_back

using namespace std;
int dp[100000],a[100000];
int main()
{
    int n ;
    cin >> n;
    int ch = 1;
    dp[0] = 1;
    for (int i = 0;i<n;i++) cin >> a[i];
    for (int i = 1;i<n;i++)
    {
        if (a[i]>=a[i-1]) ch++;
        else ch = 1;
        dp[i] = max(dp[i-1],ch);
    }
    cout << dp[n-1];
    return 0;
}
