#include <bits\stdc++.h>

using namespace std;

int main()
{
    freopen("20.in","r",stdin);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0;i<n;i++) cin >> a[i];
    int i = 0;
    long long ans = 0;
    while (i<n-1)
    {
        int no = a[i];
        while (a[i]>=a[i+1]) i++;
        ans+=no-a[i];
        while (a[i]<=a[i+1]) i++;
    }
    if (ans == 0)
    {
        int i = 1;
        ans = a[0]-a[1];
        while (i<n-1)
        {
            if (a[i]-a[i+1]>ans) ans = a[i]-a[i+1];
            i++;
        }
    }
    cout << ans;
    return 0;
}


