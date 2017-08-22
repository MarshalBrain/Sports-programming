#include <bits\stdc++.h>

using namespace std;

int main()
{
    vector <long long> a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(),a.end());
    long long ans = 2*a[2]-a[1]-a[0];
    if (a[0]!=a[2]) ans-=1;
    if (a[1]!=a[2]) ans-=1;
    if (ans<0) {cout << 0;return 0;}
    cout << ans;
    return 0;
}
