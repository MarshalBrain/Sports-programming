#include <bits\stdc++.h>

using namespace std;
long long ans;
const int M=5e3;
char s[M];
int main()
{
    freopen("in1.txt","r",stdin);
    freopen("out9.txt","w",stdout);
    gets(s);
    int j = 0, n = strlen(s);
   // cout << s << endl;
    while(j<n)
    {
        if ((int)s[j]>=48 && (int)s[j]<=57)
        {
            string ss;
            while ((int)s[j]>=48 && (int)s[j]<=57)
            {
                ss+= s[j];
                j++;
            }
            long long ch = atoi(ss.c_str());
            ans+=ch;
         //   cout << ans << " " << ch << endl;
        }
        j++;
    }
    cout << ans;
    return 0;
}
