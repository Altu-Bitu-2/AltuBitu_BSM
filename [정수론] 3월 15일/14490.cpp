#include <iostream>


using namespace std;

int gcdRecursion(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcdRecursion(b, a % b);
}



int main() {

	int nl, nr, result;
	char k;

	cin >> nl >> k >> nr;


	if (nl < nr) {
		result = gcdRecursion(nl, nr);
	}
	else {
		result = gcdRecursion(nr, nl);
	}

	cout << nl / result << k << nr / result;



}