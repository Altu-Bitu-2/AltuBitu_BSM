#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>

//평균값이 -0이 나오는 경우를 주의하자

using namespace std;

void average(vector<int> vect) {

	int n = vect.size();
	double sum;
	sum = accumulate(vect.begin(), vect.end(), 0);

	if (round(sum / n) == -0) {
		cout << 0 << "\n";
	}
	else
	{
		cout << round(sum / n) << "\n";
	}
	
}


void median(vector<int> vect) {
	sort(vect.begin(), vect.end());
	int i = (vect.size() / 2);
	cout << vect[i] << "\n";
}


void mode(vector<int> vect) {
	map<int, int> maptmp;
	vector<int> vectmp;

	int max;

	for (int i = 0; i < vect.size(); i++) {
		maptmp[vect[i]] += 1;
	}
	
	max = maptmp.begin()->second;

	for (auto iter = maptmp.begin(); iter != maptmp.end(); iter++) {
		if (iter->second >= max) {
			max = iter->second;
		}
	}

	for (auto iter = maptmp.begin(); iter != maptmp.end(); iter++) {
		if (max == iter->second) {
			vectmp.push_back(iter->first);
		}
	}

	if (vectmp.size() != 1) {
		cout << vectmp[1] << "\n";
	}
	else cout << vectmp[0] << "\n";
}


void range(vector<int> vect) {
	int max = *max_element(vect.begin(), vect.end());
	int min = *min_element(vect.begin(), vect.end());

	cout << max - min << "\n";
}




int main() {
	
	vector<int> vlist;
	int num, tmp;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> tmp;
		vlist.push_back(tmp);
	}

	average(vlist);
	median(vlist);
	mode(vlist);
	range(vlist);

	return 0;
}