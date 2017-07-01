#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n+3][n+3],b[n+3][n+3];

    for (int i = 1;i<=n;i++)
        for (int j = 1;j<=n;j++) cin >> a[i][j];
    for (int i = 1;i<=n;i++)
        for (int j = 1;j<=n;j++)
        {
            if (a[i][j] == 0 && i!=j) {b[i][j] = 100000;continue;}
            b[i][j] = a[i][j];
        }
    for (int k = 1;k<=n;k++)
        for (int i = 1;i<=n;i++)
            for (int j = 1;j<=n;j++)
                if (b[i][k]<100000 && b[k][j]<100000)
                    if (b[i][k]+b[k][j]<b[i][j]) b[i][j] = b[i][k]+b[k][j];
    for (int i = 1;i<=n;i++)
    {
        for (int j = 1;j<=n;j++) cout << b[i][j] << " ";
        cout << endl;
    }
    return 0;
}
