#include <bits\stdc++.h>

using namespace std;

double a[100000];
int main()
{
    int n,w;
    cin >> n >> w;
    n*=2;
    for (int i = 0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    double m = 0;
    if (a[0]*2>a[n/2]) m = a[n/2]/4*n+a[n/2]*n/2;
    else m = a[0]*n+a[0]*n/2;
    if (m>w) cout << w;
    else cout << m;
    return 0;
}
