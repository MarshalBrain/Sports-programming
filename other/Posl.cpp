#include <iostream>
using namespace std;
int main() {
  // put your code here
    int no,ko,sr,n,ans = 0;
    cin >> n;
    if (n == 0){ cout << 0;return 0;}
    no = n;
    cin >> n;
    if (n == 0){cout << 0;return 0;}
    sr = n;
    while (n!=0)
    {
        cin >> n;
        if (n == 0) {break;
                    }
        ko = n;
        if (sr>no && sr>ko) ans++;
        no = sr;
        sr = ko;
    }
    cout << ans;
  return 0;
}
