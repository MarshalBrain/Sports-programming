#include <bits\stdc++.h>
#define pb push_back
using namespace std;
vector <int> a;
vector <int> pref;
int n,m;
void make_prefix()
{
    pref.pb(a[0]);
    for (int i = 1;i<n;i++)
    {
        pref.pb(pref[i-1] + a[i]);
    }
}
int set_summ(int x, int y)
{
    if (x>1) return(pref[y-1]-pref[x-2]);
    else return (pref[y-1]);
}
int main()
{
    cin >> n;
    for (int i = 0;i<n;i++)
    {
        int temp = 0;
        cin >> temp;
        a.pb(temp);
    }
    make_prefix();
    cin >> m;
    for (int i = 0;i<m;i++)
    {
        int l,r;
        cin >> l >> r;
        cout << set_summ(l,r);
    }
    return 0;
}
