#include <bits\stdc++.h>

using namespace std;
const int MAXN = 2e9;
int main()
{
    set<int> a;
    set<int> b;
    int n,m;
    cin  >> n >> m;
    for (int i = 0;i<n;i++)
    {
        int temp;
        cin >> temp;
        a.insert(temp);
    }
    for (int i = 0;i<m;i++)
    {
        int temp;
        cin >> temp;
        b.insert(temp);
    }
    set<int> :: iterator it = a.begin();
    set<int> :: iterator jt = b.begin();
    int maxi = 0;
    while (it != a.end())
    {
        int now = MAXN;
        while (abs(*it-*jt)<now && jt!=b.end())
        {
            now = abs(*it-*jt);
            jt++;
        }
        jt--;
       // cout << *it << " " << now << endl;
        if (now>maxi) maxi = now;
        it++;
    }
    cout << maxi;
    return 0;
}
