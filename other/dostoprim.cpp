#include <bits\stdc++.h>

using namespace std;
int ans[5001], a[5001][5005],f[5005];
int main()
{
    int n,m,t;
    cin >> n >> m >> t;
    for (int i = 0;i<m;i++)
    {
        int x,y,ch;
        cin >> x >> y >> ch;
        a[x-1][y-1] = ch;
    }
    for (int i = 0;i<n;i++)
    {
        a[i][n] = 0;
        a[i][n+1] = 0;
        a[i][n+2] = 0;
        f[i] = false;
    }
    for (int i = 0;i<n-1;i++)
    {
        int max = 0, l = 0;
        for (int j = 0;j<n;j++)
            if (!f[j] && a[j][n+1]>max)
        {
            max = a[j][n+1];
            l = j;
        }
        f[l] = true;
        for (int j = 0;j<n;j++)
        {
            if (!f[j] && a[l][n+2]+a[l][j]<=t && a[l][j] && a[l][n+1]+1>a[j][n+1])
            {
                cout << j << " " << l  << endl;
                a[j][n+1]+=a[l][n+1]+1;
                a[j][n+2]+=a[l][j]+a[l][n+2];
                a[j][n] = l;
            }
        }
    }
    for (int i = 0;i<n;i++)
    {
        for (int j = 0;j<=n+2;j++)
        cout << a[i][j] << " ";
        cout << endl;
    }
    cout << a[n-1][n+1]+1 << endl;
    int i = n-1,j = 1;
    ans[0] = n;
    while (i!=0)
    {
        ans[j] = a[i][n]+1;
        i = a[i][n];
        j++;
    }
    for (int i = j-1;i>=0;i--)
        cout << ans[i] << " " ;
    return 0;
}
