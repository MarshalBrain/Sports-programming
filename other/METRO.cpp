#include <bits\stdc++.h>

using namespace std;
const int MAXN = 2e9;
const int siz = 1e3+5;
int a[siz][siz];
bool f[siz];
int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i = 0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
        a[x][n+1]++;
        a[y][n+1]++;
    }
    for (int i = 1;i<=n;i++)
    {
        int k = 0;
        int mi = MAXN;
        for (int j = 1;j<=n;j++)
        {
            if (a[j][n+1]<mi && !f[j])
            {
                mi = a[j][n+1];
                k = j;
            }
        }
        f[k] = 1;
        cout << k << endl;
        for (int j = 1;j<=n;j++)
        {
            if (a[k][j] == 1)
            {
                a[k][j] = 0;
                a[j][k] = 0;
                a[j][n+1]--;
                a[k][n+1]--;
            }
        }
    }
    return 0;
}
