#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;
int main() {
  // put your code here
    int n ;
    vector <int> a;
    cin >> n;
    int ans = 0 ;
    for (int i = 0;i<n;i++)
    {
        int temp = 0;
        cin >> temp;
        a.pb(temp);
    }
    sort(a.rbegin(),a.rend());

    /*for (int i = 0;i<a.size();i++)
    {

        cout << a[i] << " " ;
    }*/
    int i = 0;
    while (i<n-1)
    {
        if (a[i] == a[i+1])
        {
            int k = 0;
            while (a[i] == a[i+1])
            {
                k++;
                i++;
            }
          //0  cout << k << endl;
            int temp = 0;
            for (int i = 1;i<=k;i++)
            {
                temp+=i;
            }
            ans+=temp;
        }
        i++;
    }
    cout << ans;
  return 0;
}
