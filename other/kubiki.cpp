#include <bits\stdc++.h>

using namespace std;
int ans = 1;
bool a[300][300][300];
void piramid(int u, int i, int k, int f)
{
 //   system("pause");
    if (f!=0 && i+1<k)
    {
      //  cout << "f " << u << " " << i+1 << " " << k << " " << ans+1 << endl;
        if (a[u][i+1][k] == 0) {ans++;a[u][i+1][k] = 1;}
        piramid(u,i+1,k,f-1);
    }
    if (i+1<k-1)
    {
      //  cout << "k " << u << " " << i+1 << " " << k-1 << " " << ans+1 << endl;
        if (a[u][i+1][k-1] == 0) {ans++;a[u][i+1][k-1] = 1;}
        if (u==1) piramid(u,i+1,k-1,f);
        else piramid(u,i+1,k-1,f+1);
    }
    if (i+1 == k)
    {
      //  cout << "p " << u+1 << " " << 0 << " " << i << " " << ans << endl;
        piramid(u+1,0,i,f);
    }
    if (i+1 == k-1)
    {
       // cout << "p " << u+1 << " " << 0 << " " << i << " " << ans << endl;
        piramid(u+1,0,i,f+1);
    }
}
int main()
{
    int n;
    cin >> n;
    piramid(1,0,n,0);
    cout << ans;
    return 0;
}
