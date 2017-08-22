#include <bits\stdc++.h>
#define mp make_pair
using namespace std;
pair <double, int> ans[200];
int main()
{
    int svv = 0;
    int i = 1;
    int n = 1;
    ifstream in("C:\\Users\\Антон Жуков\\Documents\\input.txt");
  //  ofstream out;
    //out.open("C:\\Users\\Антон Жуков\\Documents\\output.txt");
    in >> n;
    while (i<=n)
    {
        in.close();
        in.open("C:\\Users\\Антон Жуков\\Documents\\input.txt");
        int p[201],q[201];
        pair <double, int> a[201];
        fill(p,p+n,0);
        fill(q,q+n,0);
        int ch;
        cin >> ch;
        int k = 0;
        cout << "!";
        for (int j = 0;j<n;j++)
        {
            in >> p[j];
            k+=p[j];
        }
        for (int j = 0;j<n;j++)
        {
            in >> q[j];
        }
        int sv = 0;
        for (int j = 0;j<k;j++)
        {
            int x,y;
            in >> x >> y;
            if (y == i)
            {
                for (int l = 0;l<4;l++)
                {
                    int ch;
                    in >> ch;
                    a[sv].first+=ch;
                }
                a[sv].second = x;
                sv++;
            }
            else {
                    int ch;
                    for (int l = 0;l<4;l++) in >> ch;
            }
        }
        sort(a,a+n);
        int j;
        for (j = 0;j<q[i];j++)
        {
            if (a[j].first!=0)
            {
                ans[svv].first = a[j].first;
                ans[svv].second = a[j].second;
                svv++;
            }
            else break;
        }
        while((a[j].first-a[j-1].first)<0.0001)
        {
            if (a[j].first!=0)
            {
                ans[svv].first = a[j].first;
                ans[svv].second = a[j].second;
                svv++;
                j++;
            }
            else break;
        }
        cout << "!";
        i++;
    }
    sort(ans,ans+svv-1);
   // out << svv;
  //  for (int i = 0;i<svv;i++) out << ans[i].first << " " << ans[i].second << endl;
  //  out.close();
    return 0;
}
