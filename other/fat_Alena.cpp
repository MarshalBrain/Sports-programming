#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    int mi = min(n,m), ma = max(n,m);
    long long ans = 0;
    int ch = n+m - (n+m)%5;
    //cout << ch << endl;
    //ans+= (n+m) % 5;
    while (ch > 0)
    {
        if (ch>ma)
        {
            ans+=(mi-ch+ma)+1;
            ch-=5;
        }
        if (ch == 0) break;
        //cout << ch << " " << ans << endl;
        if (ch <= ma && ch > mi)
        {
            ans+=mi;
            ch-=5;
        }
        if (ch == 0) break;
       // cout << ch << " " << ans << endl;
        if (ch<=mi)
        {
            ans+=(ch-1);
            ch-=5;
        }
        if (ch == 0) break;
     //   cout << ch << " " << ans << endl;
    }
    cout << ans;
    return 0;
}
