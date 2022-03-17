#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;



int main() {

	int num, tmp;
	vector<int> vcard;
	deque <int> dqcard;

	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> tmp;
		vcard.push_back(tmp);
	}

	reverse(vcard.begin(), vcard.end());
	for (int j = 1; j <= num; j++) {
		if (vcard[j - 1] == 1) {
			dqcard.push_front(j);
		}
		else if (vcard[j - 1] == 2) {
			int t = dqcard.front();
			dqcard.pop_front();
			dqcard.push_front(j);
			dqcard.push_front(t);
		}
		else if (vcard[j - 1] == 3) {
			dqcard.push_back(j);
		}
	}



	for (auto iter = dqcard.begin(); iter != dqcard.end(); iter++) {
		cout << *iter << " ";
	}


	return 0;
}