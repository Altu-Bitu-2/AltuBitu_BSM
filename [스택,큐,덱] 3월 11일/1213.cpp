#include <iostream>
#include <string>
#include <map>
#include <deque>

using namespace std;


void changename(string& s) {
	
	string st;
	map <char, int> mapst;
	deque<char> dst;

	int tmp = 0;

	if (s.length() % 2 == 0) {
		for (int i = 0; i < s.length(); i++) {
			mapst[s[i]] += 1;
		}
		
		//짝수문자열에서 불가능한 경우
		for (auto j = mapst.begin(); j != mapst.end(); j++) {
			if (j->second % 2 != 0) {
				cout << "I'm Sorry Hansoo" << "\n";
				return;
			}
		}

		for (auto k = mapst.rbegin(); k != mapst.rend(); k++) {
			for (int test = 0; test < k->second / 2; test++) {
				dst.push_front(k->first);
				dst.push_back(k->first);
			}
		}


	}


	else {
		for (int i = 0; i < s.length(); i++) {
			mapst[s[i]] += 1;
		}

		//홀수 문자열에서 불가능한 경우
		for (auto m = mapst.begin(); m != mapst.end(); m++) {
			if (m->second % 2 == 1) {
				tmp += 1;
			}
		}
		if (tmp != 1) {
			cout << "I'm Sorry Hansoo" << "\n";
			return;
		}

		for (auto m = mapst.begin(); m != mapst.end(); m++) {
			if (m->second % 2 == 1) {
				dst.push_front(m->first);
				m->second--;
			}
		}
		for (auto k = mapst.rbegin(); k != mapst.rend(); k++) {
			for (int test = 0; test < k->second / 2; test++) {
				dst.push_front(k->first);
				dst.push_back(k->first);
			}
		}
		
	}


	//검사용 순회

	//for (auto j = mapst.rbegin(); j != mapst.rend(); j++) {
	//	cout << "[" << j->first << "]" << j->second << "\n";
	//}
	
	//출력
	for (int t = 0; t < s.length(); t++) {
		cout << dst[t];
	}
	

}


int main() {

	string name;

	cin >> name;

	changename(name);


	return 0;
}