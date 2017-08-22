#include <bits\stdc++.h>

using namespace std;
const int maxN = 1e8;
vector<int> a(maxN);
int NOK(int c, int d)
{
    int x = c, y = d;
    while (c*d!=0)
    {
        if (c>d) c%=d;
        else d%=c;
    }
    return x*y/(c+d);

}
int main()
{
    int n,k;
    cin >> n >> k;
    int i = 1, j = 0;

    while (i<=round(sqrt(n)))
    {
        if (n%i == 0) {a[j] = i;a[j+1] = n/i;j+=2;}
        i++;
    }
    j-=1;
    int ans = 0;
    for (int i = 0;i<=j;i++)
    {
        if (NOK(a[i],k)>=n) ans++;
    }
    cout << ans;
    return 0;
}
