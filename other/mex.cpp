#include <bits\stdc++.h>
using namespace std;
int a[100000];
int main()
{
    int n;
    cin >> n;
    for (int i = 0;i<n; i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    for (int i = n-1;i>0;i--)
    {
        if (a[i]-1>a[i-1])
        {
            cout << a[i]-1;
            return 0;
        }
    }
    cout << a[n-1]+1;
    return 0;
}
