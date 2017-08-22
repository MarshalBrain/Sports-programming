#include <bits\stdc++.h>
#define ll long long
using namespace std;
int n,m;
int a[1000][1000];
ll pref[1000][1000];
void precalc()
{
        pref[0][0] = a[0][0];
        for (int i = 1; i<n; i++){
            pref[i][0] = pref[i-1][0]+a[i][0];
        }
        for (int i = 1; i < m;i++)
        {
            pref[0][i] = pref[0][i-1] + a[0][i];
        }
        for (int i = 1;i<n;i++){
            for (int j = 1;j<n;j++){
                pref[i][j] = pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+a[i][j];
            }
        }
}
ll query (int x1, int y1, int x2, int y2) {
    return pref[x2][y2]
            - (x1 ? pref[x1-1][y2] : 0)
            - (y1 ? pref[x2][y1-1] : 0)
            + (x1 && y1 ? pref[x1-1][y1-1] : 0);
}
int main()
{
    cin >> n >> m;
    for (int i = 0;i<n;i++){
        for (int j = 0;j<m;j++){
            cin >> a[i][j];
        }
    }
    int k;
    cin >> k;
    precalc();
    for (int i = 0;i<k;i++)
    {
        int x,y,xx,yy;
        cin >> x >> y >> xx >> yy;
        if (y>yy) swap(y,yy);
        if (x>xx) swap(x,xx);
        cout << query(x ,y ,xx,yy) << endl;
    }
    return 0;
}
