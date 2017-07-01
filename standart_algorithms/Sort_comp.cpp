#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int maxN = 1e3;
vector<int> a(maxN);
bool comp(int c, int b)
{
   return c > b;
}
int main()
{
    int n;
    cin >> n;
    int com[n];
    for (int i = 0;i<n;i++){ cin >> a[i];com[i] = i;}
    sort(com,com+n,comp);
    for (int i = 0;i<n;i++) cout << a[com[i]] << " ";
    return 0;
}
