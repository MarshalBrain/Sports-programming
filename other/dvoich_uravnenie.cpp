#include <bits\stdc++.h>

using namespace std;
const int maxN = 40;
vector<bool> a(maxN), b(maxN);
int ans[1000000];
int main()
{
    int n ;
    cin >> n;
    int j = 0;
    int kol = 0;
    while (pow(2,j)<n) j++;
    a[0] = 1;
    int dl = 0;
    int ch = 1;
    while (ch < n)
    {
      /*  for (int l = 0;l<=dl;l++) cout << a[l];
        cout << endl;*/
        int chh = n-ch;
        int i = 0;
        while (chh>1)
        {
            b[i] = chh%2;
            i++;
            chh/=2;
        }
        b[i] = chh;
        //for (int l = 0;l<=i;l++) cout << b[l];
        int f = 0;
      //  cout << endl << max(dl,i) << endl;

        for (int l = 0;l<=max(dl,i);l++)
        {
            if (a[l]!=b[l]) f++;
        }
        if (f == 1) {ans[kol] = ch;kol++;}
        int k = 0;
        while (a[k] == 1) k++;
        if (k>dl) dl = k;
        a[k] = 1;
        k--;
        for (int l = k;l>=0;l--) a[l] = 0;
        ch++;
        if (ch>n/2) break;
    }
    cout << kol << endl;
    for (int i = 0;i<kol;i++)
        cout << ans[i] << endl;
    return 0;
}
