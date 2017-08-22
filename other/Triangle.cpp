#include <bits\stdc++.h>
using namespace std;
int a[4];
int main()
{
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    int n = 3;
    for (int i = 0; i<n; i++)
        for (int j = 0;j<n-i;j++)
          if (a[j]>a[j+1])
          {
              int w = a[j];
              a[j] = a[j+1];
              a[j+1] = w;
          }
    if (a[0]+a[1]>a[2] || a[0]+a[1]>a[3] || a[1]+a[2]>a[3])
    {
        cout << "TRIANGLE";
        return 0;
    }
    if (a[0]+a[1]==a[2] || a[0]+a[1]==a[3] || a[1]+a[2]==a[3])
    {
        cout << "SEGMENT";
        return 0;
    }
    cout << "IMPOSSIBLE";
    return 0;
}
