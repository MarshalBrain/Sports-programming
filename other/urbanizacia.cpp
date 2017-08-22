#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n,n1,n2,nx,ny;
    cin >> n >> nx >> ny;
    vector <int> a(n);
    for (int i = 0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    n1 = min(nx,ny);
    n2 = max(nx,ny);
    double ans1 = 0, ans2 = 0;
    for (int i = n-1;i>n-n1-1;i--) ans1+=(double)a[i];
    for (int i = n-n1-1;i>n-n1-n2-1;i--) ans2+=(double)a[i];
    cout << fixed << setprecision(6) << ans1/n1+ans2/n2;
    return 0;
}
