#include <bits\stdc++.h>

using namespace std;
bool f[305];
int a[305][305];
int x[305],y[305];
const int M = 2e9;
int main()
{
    freopen("intput.txt","r",stdin);
    int n;
    cin >> n;
    for (int i = 0;i<n;i++)
    {
        cin >> x[i] >> y[i];
        for (int j = i-1;j>=0;j--)
        {
            a[i][j] = pow(x[i]-x[j],2) + pow(y[i]-y[j],2);
            a[j][i] = pow(x[i]-x[j],2) + pow(y[i]-y[j],2);
        }
    }
   for (int i = 0;i<n;i++)
    {
        for (int j = 0;j<n;j++) cout << a[i][j] << " ";
        cout << endl;
    }
    int ans = M;
    for (int l = 0;l<n;l++)
    {
        for (int i = 0;i<n;i++)
        {
            a[i][n] = M;
            f[i] = false;
        }
        a[l][n] = 0;
        for (int i = 0;i<n;i++)
        {
            int mi = M;
            int now;
            for (int j = 0;j<n;j++)
            {
                if (f[j] == false && a[j][n]<mi) { mi = a[j][n];now = j;}
            }
            for (int j = 0;j<n;j++)
            {
                if (a[now][j]+a[now][n]<a[j][n]) a[j][n] = a[now][j]+a[now][n];
            }
            f[now] = true;
     //       cout << endl;
        }
        int ma = 0;
        for (int i = 0;i<n;i++)
        {
            ma += a[i][n];
         //   cout << a[i][n] << "\n";
        }
        //cout << endl << ma << endl;
        if (ma<ans) ans = ma;
    }
    cout << ans;
    return 0;
}
