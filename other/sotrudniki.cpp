#include<bits\stdc++.h>

using namespace std;
int ans(int m)
{
    int an = 1;
    for (int i = 2;i<=round(sqrt(m));i++)
    {
        if (m%i == 0) {an+=(i)+(m/i);}
    }
    return an;
}
int main()
{
    //freopen("sotrudniki2.cpp","w",stdout);
    int n,m;
    cin >> n >> m ;
    bool f = 0;
    bool ff[1500000];
    int kol =  0;
    for (int i = n;i<=m;i++)
    {
        int temp1 = ans(i),temp2 = ans(temp1);
       // cout << i << " " << temp << endl;
        if (i == temp2 && temp1 != 1 && i!=temp1 && ff[i] == 0) {/*cout << i << ", ";*/f = 1;ff[temp1] = 1;kol++;}
    }
    cout << kol;
    if (f == 0) cout << "Absent";
    return 0;
}
