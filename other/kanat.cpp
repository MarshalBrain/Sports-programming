#include <bits\stdc++.h>
#define pb push_back

using namespace std;
const int maxN = 25;
int a[maxN+1][maxN+3];
int main()
{
    freopen("11.in","r",stdin);
    vector<int> ans;
    int n, k,m;
    cin >> n >> k >> m;
    for (int i = 0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
        a[x][n+1]++;
        a[y][n+1]++;
    }
    while (k>0)
    {
        int maxi = 0, uk = 0;
        for (int j = 1;j<=n;j++)
        {
            if (a[j][n+1]>maxi) {maxi = a[j][n+1];uk = j;}
        }
        ans.pb(uk);
        k--;
   //     cout << maxi << " " << uk;
        for (int j = 1;j<=n;j++)
        {
            if (k>0)
            {
                if (a[uk][j] == 1) {ans.pb(j);k--;}
            }
            else break;
        }
        a[uk][n+1] = 0;
    }
    for (int i = 0;i<ans.size();i++) cout << ans[i] << " ";
    return 0;
}
