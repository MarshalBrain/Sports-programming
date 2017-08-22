#include <bits\stdc++.h>

using namespace std;
int a[1000][1000];
int main()
{
    freopen("20.in","r",stdin);
    int n,m;
    cin >> n >> m;
    for (int i = 0;i<m;i++)
    {
        int x, y;
        cin >> x >> y;
        int xx = x,yy = y;
        while (xx>0 && yy>0)
        {
            a[xx][yy] = 1;
            xx--;
            yy--;
        }
        xx = x;
        yy = y;
        while(xx<=n && yy > 0)
        {
            a[xx][yy] = 1;
            xx++;
            yy--;
        }
        xx = x;yy = y;
        while (xx>0 && yy<=n)
        {
            a[xx][yy] = 1;
            xx--;
            yy++;
        }
        xx = x;yy = y;
        while (xx <=n && yy <=n)
        {
            a[xx][yy] = 1;
            xx++;
            yy++;
        }
    }
    int ans = 0;
    for (int i = 1;i<=n;i++)
        {
            for (int j = 1;j<=n;j++)
            {
                ans+=a[i][j];
            }
        }
    cout << n*n-ans;
    return 0;
}
