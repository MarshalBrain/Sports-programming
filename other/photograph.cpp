#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n+3);
    a[1] = 1;
    a[2] = 1;
    a[3] = 2;
    for (int i = 4;i<=n;i++)
    {
        a[i] = a[i-1]+a[i-3]+1;
    }
    cout << a[n];
    return 0;
}
