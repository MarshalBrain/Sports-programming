#include <bits\stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector <int> a(n);
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
        for (int l = 0;l<=i;l++) cout << a[l] << " ";
        cout << endl;
    }
    return 0;
}
