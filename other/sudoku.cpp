#include <bits\stdc++.h>

using namespace std;

char a[10][10],b[10][10];
bool f[10];
int main()
{
    int n;
    for (int i = 0;i<9;i++)
        for (int j = 0;j<9;j++)
        {
            cin >> a[i][j];
         //   if (a[i][j]!='*') f[i][j] = 2;
        }
    for (int l = 0;l<n;l++)
    {
        bool ff = 0;
        for (int i = 0;i<9;i++)
        {
            for (int j = 0;j<9;j++)
            {
                cin >> b[i][j];
                if (b[i][j]!=a[i][j] && a[i][j] == '0' || a[i][j] != '1' ||
                        a[i][j] == '2' ||
                        a[i][j] == '3' ||
                        a[i][j] == '4' ||
                        a[i][j] == '5' ||
                        a[i][j] == '6' ||
                        a[i][j] == '7' || a[i][j] == '8' || a[i][j] == '9')
                     {cout << "N"; ff = 1;break;}
            }
            if (ff == 1) break;
        }
        if (ff == 1) continue;
        int i = 0;
        int j = 0;
        while (i<9)
        {
            for (int l = i;l<i+3;l++)
            {
                if (ff == 1) break;
                for (int k = j;k<j+3;k++)
                {
                    if (a[l][k] != '0' &&
                        a[l][k] != '1' &&
                        a[l][k] != '2' &&
                        a[l][k] != '3' &&
                        a[l][k] != '4' &&
                        a[l][k] != '5' &&
                        a[l][k] != '6' &&
                        a[l][k] != '7' && a[l][k] != '8' && a[l][k] != '9')                        {
                            cout << "N";
                            ff = 1;
                            break;
                        }
                    int ch = (int)a[l][k];
                    f[ch] = 1;
                }
            }
            if (ff == 1) break;
            if (j == 6)
            {
                j = 0;
                i+=3;
            }
            else j+=3;
        }
        for (int l = 0;l<9;l++)
        {
            bool ff = 0;
            fill(f,f+9,0);
            for (int k = 0;k<9;k++)
            {
                if (a[l][k] != '0' &&
                   a[l][k] != '1' &&
                   a[l][k] != '2' &&
                   a[l][k] != '3' &&
                   a[l][k] != '4' &&
                   a[l][k] != '5' &&
                   a[l][k] != '6' &&
                   a[l][k] != '7' && a[l][k] != '8' && a[l][k] != '9')
                   {
                       ff = 1;
                       break;
                   }
                int ch = (int)a[l][k];
                f[ch] = 1;
            }
            if (ff == 1) break;
        }
        if (ff == 0)
        {
            for (int i = 0;i<9;i++)
            {
                if (f[i] == 0)
                {
                    cout << "N";
                    ff = 1;
                    break;
                }
            }
            if (ff == 0) cout << "Y";
        }
        for (int l = 0;l<9;l++)
        {
            bool ff = 0;
            fill(f,f+9,0);
            for (int k = 0;k<9;k++)
            {
                if (a[k][l] != '0' &&
                   a[k][l] != '1' &&
                   a[k][l] != '2' &&
                   a[k][l] != '3' &&
                   a[k][l] != '4' &&
                   a[k][l] != '5' &&
                   a[k][l] != '6' &&
                   a[k][l] != '7' && a[k][l] != '8' && a[k][l] != '9')
                   {
                       ff = 1;
                       break;
                   }
                int ch = (int)a[k][l];
                f[ch] = 1;
            }
            if (ff == 1) break;
        }
        if (ff == 0)
        {
            for (int i = 0;i<9;i++)
            {
                if (f[i] == 0)
                {
                    cout << "N";
                    ff = 1;
                    break;
                }
            }
            if (ff == 0) cout << "Y";
        }
    }
    return 0;
}
