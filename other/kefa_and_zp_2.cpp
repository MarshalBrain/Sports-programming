#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0, pr, ma = 1;
    cin >> pr;
    for (int i = 1;i<n;i++)
    {
        int ch;
        cin >> ch;
        if (ch>=pr) {pr = ch;ma++;}
        else {ans = max(ans,ma);ma = 1;pr = ch;}
    }
    ans = max(ans,ma);
    cout << ans;
    return 0;
}
