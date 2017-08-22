#include <bits\stdc++.h>

using namespace std;
const int MAXN = 2e9;
const int siz = 1e2+1;
int a[siz][siz];
int b[siz];
bool f[siz];
int main()
{
    freopen("pathfind.10.in","r",stdin);
    int n,m,ms = 0;
    cin >> n >> m;
    for (int i = 1;i<=n;i++)
        for (int j = 1;j<=n;j++) cin >> a[i][j];
    for (int i = 1;i<=n;i++) {b[i] = MAXN;f[i] = false;}
    b[m] = 0;
    for (int i = 1;i<=n;i++)
    {
        int mi = MAXN,l = 0;
        for (int j = 1;j<=n;j++)
        {
            if (b[j]<mi && f[j] == false)
            {
                mi = b[j];
                l = j;
            }
        }
        f[l] = true;
        for (int j = 1;j<=n;j++)
            if (a[l][j] == 1 && f[j] == false && b[l]+a[l][j]<b[j]) {b[j] = b[l]+a[l][j];if (b[j]>ms) ms = b[j];}
    }
    //for (int i = 1;i<=n;i++) cout << b[i] << " ";
    for (int i = 0;i<=ms;i++)
    {
        for (int j = 1;j<=n;j++)
            if (b[j] == i) {cout << j << " ";}
        cout << endl;
    }
    return 0;
}
