#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n,x,y;
    cin >> n >> x >> y;
    int l = 0,r = max(x,y)*(n-1);
    while (l!=r)
    {
        int m = (l+r)/2+1;
        double k = m/x+m/y;
        if (k<(double)(n-1)) l = m+1;
        else r = m;
    }
    cout << r+min(x,y);
    return 0;
}
