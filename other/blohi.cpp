#include <bits\stdc++.h>

using namespace std;
const int s = 80,ss = 200;
int an[ss];

int NOD(int ch1,int ch2)
{
    while (ch1 != 0 && ch2 != 0)
    {
        if (ch1 > ch2) ch1 = ch1%ch2;
        else ch2 = ch2%ch1;
    }
    return ch1+ch2;
}
int main()
{
    ios_base::sync_with_stdio(false);
   // freopen("7.IN","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    int siz = 0;
    cin >> n;
    long long ans = n;
    vector <int> a(n),b(n);
    for (int i = 0;i<n;i++) a[i] = 1;
    int i = n-1;
    while (i>0)
    {
        int j = i;
        bool f  = 0;
        int now = 0,nowi = 0;
        for (int l = 0;l<=i;l++)
        {
            if (a[l]>now) {now = a[l];nowi = l;}
        }
        while (j>=0)
        {
            if (now-a[j]>1){f = 1;break;}
            j--;
        }
        if (f == 0) {a[i-1]+=a[i];i--;}
        else {a[j]++;a[nowi]--;}
        f = 0;
        for (int l = 0;l<=i;l++)
        {
            //cout << "!";
            if (f == 1) break;
            for (int k = l+1;k<=i;k++)
            {
              /*  cout << "!";
                cout << NOD(a[l],a[k]) << " ";*/
                if (NOD(a[l],a[k]) != 1) {f = 1;break;}
            }
        }
        if (f == 0)
        {
            int ch = 1;
            for (int l = 0;l<=i;l++) ch*=a[l];
            if (ch>ans)
            {
                ans = ch;
                for (int l = 0;l<=i;l++) {b[l] = a[l];}
                siz = i;
            }
        }
    }
    //for (int i = 0;i<=siz;i++) cout << b[i] << " ";
    int j = 0;
    int no = 0;
    int ch = 0;
    cout << ans << endl;
    for (int i = 0;i<=siz;i++)
    {
        no = j+1;
        j++;
        ch+=b[i];
        while (j<ch)
        {
            cout << j << " " << j+1 << " ";
            j++;
        }
        cout << j << " " << no << " ";
    }
    //for (int i = 1;i<=n*2;i++) cout << an[i] << " ";
    return 0;
}
