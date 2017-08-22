#include <iostream>
#include <cmath>
#include <stdlib.h>
#define pb push_back

using namespace std;

int a[110][110];
bool f[110];
int main()
{
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
    int ans = 0;
    while (true)
    {
        bool ff = 0;
        fill(f,f+n,false);
    /*    for (int i = 1;i<=n;i++)
        {
            for (int j = 1; j<=n+1; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }*/
        for (int i = 1;i<=n;i++)
            if (a[i][n+1] == 1 && f[i] == 0)
            {
                for (int j = 1;j<=n;j++)
                 if (a[i][j] == 1)
                    {
                        ff = 1;
                        a[i][j] = 0;
                        a[i][n+1]--;
                        a[j][i] = 0;
                        a[j][n+1]--;
                        f[j] = 1;
                    }
            }
        if (ff == 0) break;
        else ans++;
    }
    cout << ans;
    return 0;
}
