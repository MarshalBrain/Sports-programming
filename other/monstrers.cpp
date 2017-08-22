#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1;i<=n;i++) cin >> a[i];
    cin >> m;
    vector<int> b(m+1);
    for (int i = 1;i<=m;i++) cin >> b[i];
    int se = 0;
    int i = 1,j = 1;
    while (i<=n)
    {
        int ch = 0,ma = 0,ukm = 0,no = i,sez = 0;
        char c;
        while (ch!=b[j] && i<=n)
        {
            ch+=a[i];
           // cout << b[j] << " " << ch << endl;
            if (ch>b[j]) {cout << "NO";return 0;}
            if (a[i]>ma)
            {
                if (ch == b[j])
                    if (i>no)
                        {if (a[i]-a[i-1]>0) {ma = a[i];ukm = i;c = 'L';}}
                    else {ma = a[i];ukm = i;i++;break;}
                if (i == no)
                {
                    if (a[i]-a[i+1]>0) {ma = a[i];ukm = i;c = 'R';}
                }
                if (i>no && ch!=b[j] && a[i]-a[i+1]>0) {ma = a[i];ukm = i;c = 'R';}
                if (i>no && ch!=b[j] && a[i]-a[i-1]>0) {ma = a[i];ukm = i;c = 'L';}
            }
            i++;
        }
        if (ch<b[j]) {cout << "NO";return 0;}
        j++;
       // cout << ma << endl;
        if (ma == 0) {cout << "NO";return 0;}
    }
    cout << "YES" << endl;
    i = 1,j = 1;
    while (i<=n)
    {
        int ch = 0,ma = 0,ukm = 0,no = i,sez = 0;
        char c;
        while (ch!=b[j] && i<=n)
        {
            //if (ch>b[j]) {cout << "NO";return 0;}
            ch+=a[i];
            if (a[i]>ma)
            {
                if (ch == b[j])
                    if (i>no)
                        {if (a[i]-a[i-1]>0) {ma = a[i];ukm = i;c = 'L';}}
                    else {i++;break;}
                if (i == no)
                {
                    if (a[i]-a[i+1]>0) {ma = a[i];ukm = i;c = 'R';}
                }
                if (i>no && ch!=b[j] && a[i]-a[i+1]>0) {ma = a[i];ukm = i;c = 'R';}
                if (i>no && ch!=b[j] && a[i]-a[i-1]>0) {ma = a[i];ukm = i;c = 'L';}
            }
            i++;
        }
        j++;
        /*cout << ma << " " << ukm << " " << c << " " << i << endl;
        system("pause");*/
        int ko = i-1;
        //if (ma == 0) {cout << "NO";return 0;}
        if (c == 'L')
        {
            while (ukm>no)
            {
                cout << ukm-se << " L" << endl;
                a[ukm-1]+=a[ukm];
                sez++;
                a[ukm] = 0;
                ukm--;
            }
          //  system("pause");
            int ukkm = ukm;
            ukm++;
            while (a[ukm] == 0) ukm++;
            if (ukm<=ko) {cout << ukkm-se << " R" << endl;a[ukm]+=a[ukkm];a[ukkm]=0;ukm++;sez++;}
            while (ukm<ko)
            {
                cout << ukm-se-sez << " R" << endl;
                a[ukm+1]+=a[ukm];
                sez++;
                a[ukm] = 0;
                ukm++;
            }
            se+=sez;
        }
        if (c == 'R')
        {
            while (ukm<ko)
            {
                cout << ukm-se-sez << " R" << endl;
                a[ukm+1]+=a[ukm];
                sez++;
                a[ukm] = 0;
                ukm++;
            }
            int ukkm = ukm;
            ukm--;
            while (a[ukm] == 0 && ukm>=no) ukm--;
            if (ukm<no) {se+=sez;continue;}
            if (ukm>=no) {cout << ukkm-se << " L" << endl;a[ukm]+=a[ukkm];a[ukkm]=0;ukm--;sez++;}
            while (ukm>no)
            {
                cout << ukm-se << " L" << endl;
                a[ukm-1]+=a[ukm];
                sez++;
                a[ukm] = 0;
                ukm--;
            }
            se+=sez;
            cout << se << endl;
        }
    }
    return 0;
}
