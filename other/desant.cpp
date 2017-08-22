#include <bits\stdc++.h>
using namespace std;
void dfs(int x, int y,bool ff)
{

}
int main()
{
    int n,m;
    cin >> n >> m;
    int x,y,xx,yy;
    cin >> x >> y >> xx >> yy;
    for (int i = 1;i<=n;i++)
        for (int j = 1;j<=m;j++) cin >> a[i][j];
    for (int i = 0;i<=n+1;i++)
    {
        a[i][0] = '#';
        a[i][m+1] = '#'
    }
    for (int i = 0;i<=m+1;i++)
    {
        a[0][i] = '#';
        a[n+1][i] = '#';
    }
    o[0][0] = x;
    o[1][0] = y;
    int no = 0;
    int ko = 0;
    int sv = 1;
    int sh = 0;
    while (true)
    {
        int temp = sv;
        for (int i = no;i<=ko;i++)
        {
            sh++;
            int xt = o[0][i],yt = o[1][i];
            if (a[xt][yt+1] == '.')
            {
                a[xt][yt+1] = '#';
                o[0][sv] = xt;
                o[1][sv] = yt+1;
                sv++;
                b[xt][yt+1] = sh;
            }
            if (a[xt][yt-1] == '.')
            {
                a[xt][yt-1] = '#';
                o[0][sv] = xt;
                o[1][sv] = yt-1;
                sv++;
                b[xt][yt-1] = sh;
            }
            if (a[xt+1][yt] == '.')
            {
                a[xt+1][yt] = '#';
                o[0][sv] = xt+1;
                o[1][sv] = yt;
                sv++;
                b[xt+1][yt] = sh;
            }
            if (a[xt-1][yt] == '.')
            {
                a[xt-1][yt] = '#';
                o[0][sv] = xt-1;
                o[1][sv] = yt;
                sv++;
                b[xt-1][yt] = sh;
            }
        }
        if (temp == sv) break;
        if (a[xx][yy] == '#') break;
        no = ko+1;
        ko = sv-1;
    }
    for (int i = 0;i<n;i++)
        for (int j = 0;j<m;j++)
        {
            f[i][j] = 0;
        }
    dfs(i);
    return 0;
}
