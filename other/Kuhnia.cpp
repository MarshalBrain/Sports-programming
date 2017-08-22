#include <bits\stdc++.h>

using namespace std;

double a[20], b[20];
int main()
{
    int n,v;
    cin >> n >> v;
    for (int i = 0;i<n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0;i<n;i++)
    {
        cin >> b[i];
    }
    double x = 100000, d = 0,c = 0;
    for (int i = 0;i<n;i++)
    {
        if ((b[i]/a[i])<x)
        {
            x = (double) b[i]/a[i];
            d = b[i];
            c = a[i];
        }
    }
    double ans = 0;
    for (int i = 0;i<n;i++)
    {
        ans +=a[i] * x;
    }
    if (ans>v) cout << v;
    else cout << ans;
    return 0;
}
