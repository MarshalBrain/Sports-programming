#include <bits\stdc++.h>

using namespace std;
char ans[255][255];
const int MAXN = 2e9;
int a[255][255],b[255][255],p[255][255];
int main()
{
    int n;
    cin >> n;
    for (int i = 1;i<=n;i++)
    for (int j = 1;j<=n;j++)
    {   char temp;
        cin >> temp;
        a[i][j] = (int)temp;
    }
    for (int i = 0;i<=n+1;i++)
    {
        a[0][i] = 0;
        a[n+1][i] = 0;
        a[i][n+1] = 0;
        a[i][0] = 0;
    }
    p[1][1] = 0;
    for (int i = 1;i<=n;i++)
        for (int j = 1;j<=n;j++)
        {
             ans[i][j]='-';
             b[i][j] = MAXN;
        }
    b[1][1] = a[1][1];
    for (int i = 1;i<=n;i++)
    {
        for (int j = 1;j<=n;j++)
        {
            if (b[i][j]+a[i][j+1]<b[i][j+1])
            {
                b[i][j+1] = b[i][j]+a[i][j+1];
                p[i][j+1] = (i-1)*n+j;
            }
            if (b[i][j]+a[i+1][j]<b[i+1][j])
            {
                b[i+1][j] = b[i][j]+a[i+1][j];
                p[i+1][j] = (i-1)*n+j;
            }
        }
    }
    int i = n,j = n;
    while(p[i][j]!=0)
    {
        ans[i][j] = '#';
        int x = i,y = j;
        if (p[i][j]%n == 0) {j = n;i = p[i][y]/n;}
        else {j = p[i][j]%n;i = p[i][y]/n+1;}
       /* cout << i << " " << j << " " << p[i][j] <<  endl;
        system("Pause");*/
    }
    ans[1][1] = '#';
    /*for (int i = 1;i<=n;i++)
    {
        for (int j = 1;j<=n;j++) cout << p[i][j] << " ";
        cout << endl;
    }*/
    for (int i = 1;i<=n;i++)
    {
        for (int j = 1;j<=n;j++) cout << ans[i][j];
        cout << endl;
    }
    return 0;
}
