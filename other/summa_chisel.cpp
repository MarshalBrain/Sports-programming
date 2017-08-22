#include <bits\stdc++.h>

using namespace std;

int main()
{
    freopen("in10.txt","w",stdout);
    //freopen("output.txt","w",stdout);
    string s;
    srand(time(NULL));
    int n = rand()% 5000 + 1;
    int i = 0;
    int prom = i * 2;
    long long full = 18000000000000000;
    bool f = 0;
    for (i = 0;i<n;i++)
    {
        if (prom == i && f == 0)
            {
                int num = rand()% 2147483647 + 1;
                if (full>0)
                {
                 cout << num << "b";
                 prom = rand()%30 + i;
                 full-=num;
             //    cout << endl << prom << endl;
                 //cout << full << endl;
                }
                else f = 1;
        }
        else
        {
            int ch = rand() % 58 + 32;
            cout << (char) ch;
        }
    }
 //   cout << endl <<full << endl << n;
    return 0;
}
