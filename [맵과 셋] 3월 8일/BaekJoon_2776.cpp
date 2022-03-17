
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

//삽입되는 요소의 크기가 커서 벡터를 이용해서 푸니 탐색이 오래걸려 시간초과남
//map이랑 set는 삽입에 시간 오래걸림
//벡터에 이진탐색 사용해서 탐색시간 줄임



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t, n, m, input, i, j ;

	//set<int> note1;
	
	cin >> t; //testcase
	
	while (t--) {
		cin >> n;
		vector<int> note1(n);

		for (int k = 0; k < n; k++) {
			cin >> note1[k];
			
		}
		sort(note1.begin(), note1.end());

		cin >> m;
		vector<int> note2(m);


		for (i = 0; i < m; i++) {
			cin >> note2[i];
			
		}

		for (j = 0; j < m; j++) {
			if (binary_search(note1.begin(), note1.end(), note2[j])) {
				cout << 1 << '\n';
			}
			else
				cout << 0 << '\n';
		}


	}

	

	return 0;
}
