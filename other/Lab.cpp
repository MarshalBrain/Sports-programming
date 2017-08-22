#include <bits\stdc++.h>

using namespace std;
char a[33][33];
int o[2][1000000], p[2][1000000];
int main()
{
    int n;
    cin >> n;
    for (int i = 1;i<=n;i++)
        for (int j = 1;j<=n;j++)
            cin >> a[i][j];
    for (int i = 0;i<=n+1;i++)
    {
        a[0][i] = '#';
        a[n+1][i] = '#';
        a[i][0] = '#';
        a[i][n+1] = '#';
    }
    /*a[0][0] = '.';
    a[0][1] = '.';
    a[1][0] = '.';
    a[n+1][n+1] = '.';
    a[n+1][n] = '.';
    a[n][n+1] = '.';*/
    int no,ko,sv, ans = 0;
    no = 0;
    ko = 0;
    sv = 1;
    o[0][0] = 1;
    o[1][0] = 1;
    int temp = 0;
    while (true)
    {
        temp = sv;
        for (int i = no;i<=ko;i++)
        {
            int x = o[0][i],y = o[1][i];
            ans++;
            if (a[x+1][y] == '.' )
            {
                a[x][y] = '@';
                o[0][sv] = x+1;
                o[1][sv] = y;
                sv++;

            }
            if (a[x-1][y] == '.' )
            {
                a[x][y] = '@';
                o[0][sv] = x-1;
                o[1][sv] = y;
                sv++;

            }

            if (a[x][y+1] == '.' )
            {
                a[x][y] = '@';
                o[0][sv] = x;
                o[1][sv] = y+1;
                sv++;

            }
            if (a[x][y-1] == '.' )
            {
                a[x][y] = '@';
                o[0][sv] = x;
                o[1][sv] = y-1;
                sv++;
            }
        }
        if (temp == sv) break;
        no = ko+1;
        ko = sv-1;
    }
    /*if (a[n][n]!='@')
    {
    if (a[x+1][y] == '#')
            {
                ans+=9;
                a[x][y] = '@';
                cout << ans << " " << i << endl;
            }
            else
                if (a[x+1][y] == '.')
                {
                    a[x][y] = '@';
                    o[0][sv] = x+1;
                    o[1][sv] = y;
                    sv++;
                }
            if (a[x-1][y] == '#')
            {
                ans+=9;
                a[x][y] = '@';
                cout << ans << " " << i << endl;
            }
            else
                if (a[x-1][y] == '.')
                {
                    a[x][y] = '@';
                    o[0][sv] = x-1;
                    o[1][sv] = y;
                    sv++;
                }
            if (a[x][y+1] == '#')
            {
                ans+=9;
                a[x][y] = '@';
                cout << ans << " " << i << endl;
            }
            else
                if (a[x][y+1] == '.')
                {
                    a[x][y] = '@';
                    o[0][sv] = x;
                    o[1][sv] = y+1;
                    sv++;
                }
            if (a[x][y-1] == '#')
            {
                ans+=9;
                a[x][y] = '@';
                cout << ans << " " << i << endl;
            }
            else
                if (a[x][y-1] == '.')
                {
                    a[x][y] = '@';
                    o[0][sv] = x;
                    o[1][sv] = y-1;
                    sv++;
                }
    no = 0;
    ko = 0;
    sv = 1;
    p[0][0] = n;
    p[1][0] = n;
    while (true)
    {
        int temp = sv;
        for (int i = no;i<=ko;i++)
        {
            int x = p[0][i], y = p[1][i];
            if (a[x+1][y] == '#')
            {
                ans+=3*3;
                a[x][y] = '@';
            }
            else
                if (a[x+1][y] == '.')
                {
                    a[x][y] = '@';
                    p[0][sv] = x+1;
                    p[1][sv] = y;
                    sv++;
                }
            if (a[x-1][y] == '#')
            {
                ans+=3*3;
                a[x][y] = '@';
            }
            else
                if (a[x-1][y] == '.')
                {
                    a[x][y] = '@';
                    p[0][sv] = x-1;
                    p[1][sv] = y;
                    sv++;
                }
            if (a[x][y+1] == '#')
            {
                ans+=3*3;
                a[x][y] = '@';
            }
            else
                if (a[x][y+1] == '.')
                {
                    a[x][y] = '@';
                    p[0][sv] = x;
                    p[1][sv] = y+1;
                    sv++;
                }
            if (a[x][y-1] == '#')
            {
                ans+=3*3;
                a[x][y] = '@';
            }
            else
                if (a[x][y-1] == '.')
                {
                    a[x][y] = '@';
                    p[0][sv] = x;
                    p[1][sv] = y-1;
                    sv++;
                }
        }
        if (temp == sv) break;
        no = ko+1;
        ko = sv-1;
    }
    }*/
    cout << ans << endl;
    return 0;
}
