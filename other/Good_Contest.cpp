#include <bits\stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0;i<n;i++)
	{
		int a,b;
		string s;
		cin >> s >> a >> b;
		if (a>2400 && b>a) 
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
