#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main() {

	string n;
	int sum = 0;

	cin >> n;

	sort(n.begin(), n.end());

	if (n[0] != '0') {
		cout << -1 << '\n';
	}
	else {
		for (auto iter : n) {
			sum += iter - '0';
		}

		if (sum % 3 == 0) {
			reverse(n.begin(), n.end());
			cout << n << "\n";
		}
		else cout << -1 << "\n";
	}
	
}

