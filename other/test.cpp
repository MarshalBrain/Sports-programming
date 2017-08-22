#include <bits\stdc++.h>

using namespace std;
int a[100000];
int main()
{
    freopen("input.txt","w",stdout);
    int n = 100000;
    cout << n << endl;
    for (int i = 1;i<=n;i++)
    {
        a[i] = i;
        cout << a[i] << " ";
    }
    int m = 100000;
    cout << endl << m << endl;
    for (int i = 1;i<=m;i++)
    {
        cout << 1 << " " << 1 << " " << 100000 << endl;
    }

return 0;
}
