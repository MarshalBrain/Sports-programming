#include <bits\stdc++.h>

using namespace std;
int a[1000];
int main()
{
    int n,k;
   // freopen("intput.txt","r",stdin);
    cin >> n >> k;
    for (int i = 0;i<n;i++)
    {
        string s;
        cin >> s;
        a[s.size()]++;
    }
    string pass;
    cin >> pass;
    int ans = pass.size();
    int min = 0, i = 0,ch = 0, max = 0;
    for (int i = 0;i<=ans;i++)
    {
        if (i<ans) min+=a[i];
        if (i<=ans) max+=a[i];
    }
    cout << min + min/k*5+1 << " " << max + (max-1)/k*5;
    return 0;
}
