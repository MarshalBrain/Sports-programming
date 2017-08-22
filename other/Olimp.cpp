#include <bits\stdc++.h>

using namespace std;
int a[1001], no[1001];
int p[202],q[202],r[202];
pair <double, int> ans[200000];
void sort1(int m, int t)
{
    int i = m, j = t, x = r[(m+t)/2];
    do
    {
        while (r[i]<x) i++;
        while (r[j]>x) j--;
        if (i<=j)
        {
            swap(a[i],a[j]);
            swap(no[i],no[j]);
            swap(r[i],r[j]);
            i++;
            j--;
        }
    } while (i<=j);
    if (m<j) sort1(m,j);
    if (i<t) sort1(i,t);
}
void sort2(int m, int t)
{
    int i = m, j = t;double x = a[(m+t)/2];
    do
    {
        while (a[i]<x && x-a[i]>0.001) i++;
        while (a[j]>x && a[j]-x>0.001) j--;
        if (i<=j)
        {
            swap(a[i],a[j]);
            swap(no[i],no[j]);
            swap(r[i],r[j]);
            i++;
            j--;
        }
    } while (i<=j);
    if (m<j) sort2(m,j);
    if (i<t) sort2(i,t);
}
void sort3(int m, int t)
{
    int i = m, j = t;double x = ans[(m+t)/2].first;
    do
    {
        while (ans[i].first<x && x-ans[i].first>0.001) i++;
        while (ans[j].first>x && ans[j].first-x>0.001) j--;
        if (i<=j)
        {
            swap(ans[i].first,ans[j].first);
            swap(ans[i].second,ans[j].second);
            i++;
            j--;
        }
    } while (i<=j);
    if (m<j) sort3(m,j);
    if (i<t) sort3(i,t);
}
int main()
{
    int n;
    cin >> n;
    int k = 0;
    for (int i = 0;i<n;i++)
    {
        cin >> p[i];
        k+=p[i];
    }
    for (int i = 0;i<n;i++)
    {
        cin >> q[i];
    }
    for (int i = 0;i<k;i++)
    {
        cin >> no[i] >> r[i];
        for (int j = 0;j<n;j++)
        {
            int ch;
            cin >> ch;
            a[i]+=ch;
        }
    }
    sort1(0,n-1);
    int i = 0;
    int j = 1;
    while (i<n)
    {
        sort2(i,i+p[j]);
        i+=p[j];
        j++;
    }
    i = 0;
    j = 0;
    while (i<k)
    {
        int l = 0;
        while (l<=q[r[i]])
        {
            if (a[i]>0.0001)
            {
                ans[j].first = a[i];
                ans[j].second = no[i];
                l++;
                i++;
                j++;
            }
        }
        if (fabs(a[i]-a[i-1])<0.0001 && r[i] == r[i-1])
        {
            while(fabs(a[i]-a[i-1])<0.0001 && r[i] == r[i-1])
            {
                if (a[i]>0.0001)
                {
                    ans[j].first = a[i];
                    ans[j].second = no[i];
                    i++;
                    j++;
                }
            }
        }
        sort3(0,j-1);
    }
    cout << j << endl;
    for (int i = 0;i<j;i++)
    {
        cout << ans[i].second << " " << ans[i].first;
    }
    return 0;
}
