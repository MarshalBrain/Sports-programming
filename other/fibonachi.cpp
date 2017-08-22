#include <iostream>
#include <vector>

using namespace std;
void solution(){
	int n;
	cin >> n;
	int a = 1, b = 1;
	for (int i = 2;i<=n;i++){
		b+=a%10;
		a=(b-a)%10;
	}
	cout << a;
}
int main(){
	solution();
 	return 0;
}