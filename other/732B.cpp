#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    vector <int> a(n);
    vector <int> b(n);
    int ans = 0;
    for (int i = 0;i<n;i++)
    {
        cin >> a[i];
    }
    for (int i = 0;i<n-1;i++)
    {
        if (a[i]+b[i]+a[i+1]<=k) {b[i+1] = k-a[i]-b[i]-a[i+1];ans+=b[i+1];}
    }
    cout << ans << endl;
    for (int i = 0;i<n;i++)
    {
        cout << a[i]+b[i] << " ";
    }
    return 0;
}
