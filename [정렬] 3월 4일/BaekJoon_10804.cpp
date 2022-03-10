#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N 21

vector<int> arr(N, 0);


int main() {

	for (int i = 1; i <= 20; i++) {
		arr[i] = i;
	}

	for (int i = 0; i < 10; i++) {
		int start, end;
		cin >> start >> end;
		
		while (start < end) {
			int tmp = arr[start];
			arr[start++] = arr[end];
			arr[end--] = tmp;
		}
	}

	//Ãâ·Â
	for (int j = 1; j <= 20; j++) {
		cout << arr[j] << ' ' ;
	}


	
	return 0;
}
