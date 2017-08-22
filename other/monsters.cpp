#include <bits\stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n;
    vector<int> a(n);
    vector<pair<int,string> > ans(n);
    for (int i = 0;i<n;i++) cin >> a[i];
    cin >> m;
    int j = 0;
    int se = 0;
    int k = 0;
    for (int i = 0;i<m;i++)
    {
        int x;
        cin >> x;
        int ch = 0;
        vector <int> c;
        while (ch<x && j<n)
        {
            ch+=a[j];
            c.push_back(a[j]);
            j++;
        }
        if (ch>x || ch < x) {cout << "NO";return 0;}
        int ma = 0,uk = 0;
        if (c.size() == 1) {ma = c[0];uk = 0;}
        if (c.size() != 1 && c[0]>ma && c[0]-c[1]>0) {ma = c[0];uk = 0;}
        for (int l = 1;l<c.size()-1;l++)
        {
            if (c[l]>ma && c[l]-c[l+1]>0 || c[l]-c[l-1]>0) {ma = c[l];uk = l;}
        }
        if (c.size() != 1 && c[c.size()-1]>ma && c[c.size()-1]-c[c.size()-2]>0) {ma = c[c.size()-1];uk = c.size()-1;}
        if (ma == 0) {cout << "NO";return 0;}
      //  cout << ma << " " << uk << endl;
        int ko = c.size();
        while(c.size()!=1)
        {
            if (ko<1) {break;}
            if (uk!=c.size()-1 && c[uk]>c[uk+1])
            {
                ans[k].first = uk+1+se;
                ans[k].second = " R";
                k++;
                c[uk+1]+=c[uk];
                vector <int > :: iterator it = c.begin();
                advance(it,uk);
                c.erase(it);
            }
            if (uk!=0 && c[uk]>c[uk-1])
            {
                ans[k].first = uk+1+se;
                ans[k].second = " L";
                k++;
                c[uk-1]+=c[uk];
                vector <int > :: iterator it = c.begin();
                advance(it,uk);
                c.erase(it);
                uk--;
            }
            ko--;

        }
        se++;
    }
    if (j!=n) {cout << "NO";return 0;}
    cout << "YES" << endl;
    for (int i = 0;i<k;i++) cout << ans[i].first << ans[i].second << endl;
    return 0;
}
