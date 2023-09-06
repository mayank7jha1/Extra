#include<iostream>
using namespace std;

int main() {

	int n;
	cin >> n;
	//cout << &n << endl;

	int i = 1;
	int sum = 0;
	while (i <= n) {
		int x;
		cin >> x;
		sum = sum + x;
		i++;
	}
	cout << sum << endl;

}
