#include <iostream>
#include <vector>

using namespace std;

int gcdRecursion(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcdRecursion(b, a % b);
}


int main() {
	long long gcd, lcm, tmp, l1, l2;
	cin >> gcd >> lcm;

	vector <long long> divisor;

	tmp = lcm / gcd;

	for (long long i = 1; i <= tmp / 2; i++) {
		if (tmp % i == 0) {
			divisor.push_back(i);
		}
	}
	
	divisor.push_back(tmp);

	//for (auto i : divisor) {
	//	cout << i << "\n";
	//}

	long long size = divisor.size();

	if (size % 2 == 0) {
		for (long j = size / 2; j < size; j++) {
			if (gcdRecursion(divisor[j], divisor[size - j - 1]) == 1){
				l1 = divisor[j] * gcd;
				l2 = divisor[size - j - 1] * gcd;
				break;
			}
		}
	}
	else {
		for (long j = size / 2; j < size; j++) {
			if (gcdRecursion(divisor[j], divisor[size - j - 1]) == 1) {
				l1 = divisor[j] * gcd;
				l2 = divisor[size - j - 1] * gcd;
				break;
			}
		}
	}

	if (l1 <= l2) {
		cout << l1 << " " << l2;
	}
	else {
		cout << l2 << " " << l1;
	}

}