#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n+3][n+3];
    vector<int> b(n+3,10000);
    vector<int> f(n+3,false);
    for (int i = 1;i<=n;i++)
        for (int j = 1;j<=n;j++) cin >> a[i][j];
    int x,y;
    cin >> x >> y;
    b[x] = 0;
    for (int i = 1;i<n;i++)
    {
        int minn = 10000;
        int k = 0;
        for (int j = 1;j<=n;j++)
        {
            if (b[j] < minn && !f[j]) {minn = b[j];k = j;}
        }
        f[k] = true;
        for (int j = 1;j<=n;j++)
        {
            if (!f[j] && a[k][j] == 1 && b[k]+a[k][j]<b[j])
            {
                b[j] = b[k]+a[k][j];
                a[j][n+1] = k;
            }
        }
    }
    cout << b[y] << endl;
    int j = a[y][n+1];
    int ans[n+3];
    int i = 0;
    ans[i] = y;
    while (j!=x)
    {
        ans[i+1] = j;
        j = a[j][n+1];
        i++;
    }
    cout << x << " ";
    for (int l = i;l>=0;l--) cout << ans[l] << " ";
    return 0;
}
