#include <bits\stdc++.h>

using namespace std;
const int siz = 1e7;
int a[siz],b[siz];
int n;
void DUDEC1(char ch)
{
    int i = 0;
    if (ch == 'D') i = 2;
    else i = 1;
    int j = 1;
    while (i<=n)
    {
        b[i] = a[j];
        i+=2;
        j++;
    }
    if (ch == 'D') i = 1;
    else i = 2;
    while (i<=n)
    {
         b[i] = a[j];
         i+=2;
         j++;
    }
}
void DUDEC2(char ch)
{
    int i = 0;
    if (ch == 'D') i = 2;
    else i = 1;
    int j = 1;
    while (i<=n)
    {
        a[i] = b[j];
        i+=2;
        j++;
    }
    if (ch == 'D') i = 1;
    else i = 2;
    while (i<=n)
    {
         a[i] = b[j];
         i+=2;
         j++;
    }
}
int main()
{
    freopen("13.in","r",stdin);
    /*freopen("output.txt","w",stdout);*/
    int k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 1;i<=n;i++) a[i] = i;
    DUDEC1(s[0]);
    for (int i = 1;i<s.size();i++)
    {
        if (i % 2 !=0) DUDEC2(s[i]);
        else DUDEC1(s[i]);
    }
    if (s.size() % 2 == 0) cout << a[k];
    else cout << b[k];
    return 0;
}
