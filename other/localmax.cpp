#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
  // put your code here
    int n=0,s = 0, a;
    double sum = 0,q = 0;
    for (int i = 0; 1==1; i++)
    {
        cin >> a;
        if (a==0) break;
        n++;
        sum+=a;
        s+=a*a;
    }
    int x = (int)sum;
   // cout << x << " ";
    sum/=n;
   // cout << sum <<
    q = (s+n*sum*sum-2*sum*x)/(n-1);
    cout << fixed << setprecision(11);
    cout << sqrt(q);
  return 0;
}
`
