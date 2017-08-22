#include <bits\stdc++.h>

using namespace std;

int main()
{
    freopen("drying_6_input.txt","r",stdin);
    int n,r;
    cin >> n >> r;
    pair<int, pair<int, int> > wi[n];
    pair<int, int> ans[n];
    for (int i = 0;i<n;i++)
    {
        int temp1,temp2;
        cin >> temp1 >> temp2;
        wi[i].second.first = temp1;wi[i].second.second = i;wi[i].first = temp2;
    }
    sort(wi,wi+n);
    //for (int i = 0;i<n;i++) cout << wi[i].second.first << " " << wi[i].first << " " << wi[i].second.second << endl;
    int time_now = 0;
    int k = 0;
    for (int i = 0;i<n;i++)
    {
        if (wi[i].second.first<=wi[i].first) continue;
        ans[k] = make_pair(time_now,wi[i].second.second+1);
        k++;
        time_now+=(wi[i].second.first-wi[i].first)/(r-1);
        if (time_now>wi[i].first) {cout << "Impossible";return 0;}
    }
    for (int i = 0;i<k;i++) cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}
