#include <bits\stdc++.h>

using namespace std;

int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int ans = a/d;
    b *= 2;
    b+=a%d;
    int sh = d%2 == 0 ? d : d+1;
    while (b>=d)
    {
        ans++;
        b-=sh;
    }
    c*=3;
    c+=b;
    if (d%3 == 0) sh == d;
    if (d%3 == 1) sh == d+2;
    if (d%3 == 2) sh == d+1;
    while (c>d)
    {
        c-=sh;
        ans++;
    }
    cout << ans;
    return 0;
}
