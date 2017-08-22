#include <bits\stdc++.h>

using namespace std;
const int maxN = 50;
int dp[maxN][10];
int main()
{
    string s;
    cin >> s;
    if (((int)s[1]+1)%2 == 0) dp[1][1] = 1;
    else dp[1][1] = 2;
    for (int i = 1;i<=s.size();i++)
        for (int j = 0;j<=9;j++)
        {
            if (((int)s[i-1]+j)%2 == 0) dp[i][j] = dp[i-1][j]+dp[i][j-1]+1;
            else  dp[i][j] = dp[i-1][j]+dp[i][j-1]+2;
        }
    cout << dp[s.size()][9];
    return 0;
}
