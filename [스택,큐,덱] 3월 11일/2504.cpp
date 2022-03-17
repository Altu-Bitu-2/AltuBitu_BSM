#include <iostream>
#include <stack>
#include <string>


using namespace std;



int main() {


	string s;
	cin >> s;
	stack <char> st_str;

	int temp = 1;
	int answer = 0;
	bool check = true;


	for (int i = 0; i < s.length(); i++) {

		if (s[i] == '(') {
			temp *= 2;
			st_str.push(s[i]);
		}

		else if (s[i] == ')') {
			
			if (st_str.empty() || st_str.top() != '(') {
				check = false;
				break;
			}
			else {
				if (s[i - 1] == '(') {
					answer += temp;
				}
				st_str.pop();
				temp /= 2;
			}
		}

		else if (s[i] == '[') {
			temp *= 3;
			st_str.push(s[i]);
		}

		else if (s[i] == ']') {
			if (st_str.empty() || st_str.top() != '[') {
				check = false;
				break;
			}

			else {
				if (s[i - 1] == '[') {
					answer += temp;
				}
				st_str.pop();
				temp /= 3;
			}
		}
	}

	if (check == false || !st_str.empty()) {
		cout << '0' << '\n';
	}
	else {
		cout << answer;
	}

	return 0;

}