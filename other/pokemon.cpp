#include <bits\stdc++.h>
#define pb push_back
using namespace std;
/*struct none
{
   vector <int> x;
   int kol;
   char sb;
};*/
const int MAXN = 2e9;
int main()
{
    int n;
    cin >> n;
    vector <char> a;
    set<char> b,c;
    for (int i = 1;i<=n;i++)
    {
        char temp;
        cin >> temp;
        a.pb(temp);
        b.insert(temp);
    }
    if (n == b.size()) {cout  << n; return 0;}
    int ans = MAXN;
    int i = 1;
    set<char> :: iterator it = c.end();
   /* while (it != b.end())
    {
        cout << *it << " ";
        it++;
    }*/
    while(i<=n)
    {
        c = b;
        int temp = 0;
        int j = i;
        while (c.size()!=0 && j<=n)
        {
            if (c.find(a[j])!=c.end()) c.erase(c.find(a[j]));
            temp++;
            j++;
        }
    //                    cout << c.size();
        if (c.size()!=0) break;
        if (temp < ans) ans = temp;
        i++;
    }
    cout << ans;
    return 0;
}
