#include <bits\stdc++.h>

using namespace std;
bool f[305];
int a[305][305];
int x[305],y[305];
const int M = 2e9;
int mi = M;
int ans = 0;
int k;
void dfs(int v, int n, int k, int ans)
{
    if (k == n) mi = min(mi, ans);
   f[v] = true;
   for (int i = 0;i<n;i++)
   {
       if (!f[i] && a[v][i]!=0)
       {
           dfs(i,n,k+1, ans + a[v][i]);
           f[i] = false;
           //cout << k << endl;
       }
   }
}
int main()
{
    freopen("problem.in","r",stdin);
    freopen("problem.out","w",stdout);
    int n;
    cin >> n;
    for (int i = 0;i<n;i++)
    {
        cin >> x[i] >> y[i];
        for (int j = i-1;j>=0;j--)
        {
            a[i][j] = pow(x[i]-x[j],2) + pow(y[i]-y[j],2);
            a[j][i] = pow(x[i]-x[j],2) + pow(y[i]-y[j],2);
        }
    }
    for (int i = 0;i<n;i++)
    {
        for (int j = 0;j<n;j++ ) f[j] = false;
        dfs(i,n,1,0);
    }
    cout << mi;
    return 0;
}
