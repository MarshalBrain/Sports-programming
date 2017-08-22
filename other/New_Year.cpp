#include <bits\stdc++.h>

using namespace std;

int main()
{
    int x1,x2,x3;
    cin >> x1 >> x2 >> x3;
    int maxi = max(max(x1,x2),x3);
    int mini = min(min(x1,x2),x3);
    int ans = 2147483647;
    for (int i = mini;i<=maxi;i++)
    {
        if (fabs(i-x1)+fabs(i-x2)+fabs(i-x3)<ans) ans = fabs(i-x1)+fabs(i-x2)+fabs(i-x3);
    }
    cout << ans;
    return 0;
}
