#include <iostream>
#include <queue>

using namespace std;


int main() {

	int num, k;
	queue <int> que;
	

	cin >> num >> k;

	for (int i = 1; num >= i ; i++) {
		que.push(i);
	}

	cout << "<";


	while (!que.empty()) {
		for (int i = 0; i < k - 1; i++) {
			que.push(que.front());
			que.pop();
		}

		cout << que.front();
		que.pop();

		if (!que.empty()) {
			cout << ", ";
		}
	}
	cout << ">";

	return 0;
}