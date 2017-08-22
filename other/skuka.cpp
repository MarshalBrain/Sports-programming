#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#define pb push_back
#include <stdio.h>
using namespace std;

void files()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}
long long hesh[100000];
long long dp[100000];
int main()
{
    //files()
    int n;
    vector <int> a;
   // vector<int> hesh;
    long long temp;
    cin >> n;
    for (int i = 0;i<n;i++)
    {
        cin >> temp;
        a.pb(temp);
    }
    sort(a.begin(),a.end());
    int j = 0,k = 0;
    while (j<n)
    {
        temp = 0;
        while (a[j] == a[j+1])
        {
            temp+=a[j];j++;
        }
        temp+=a[j];
        //cout << temp << endl;
        hesh[a[j]]+=temp;
        k++;
        j++;
    }
    dp[1] = hesh[1];
    for (int i = 2;i<=100000;i++)
    {
        dp[i] = max(dp[i-1],hesh[i]+dp[i-2]);
    }
    cout << dp[100000];
    return 0;
}
