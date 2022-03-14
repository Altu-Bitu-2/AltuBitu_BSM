#include <iostream>
#include <string>
#include <set>

using namespace std;


int main() {

	int str_length = 0, start, len;
	set<string> sub_string;


	string input_str = "";
	cin >> input_str;

	str_length = input_str.length();

	for (start = 0; start < str_length; start++) {
		len = 1;
		while (start + len < str_length + 1) {
			sub_string.insert(input_str.substr(start, len++));
			
		}
	}

	//for (auto iter : sub_string)	cout << iter << "\n";

	cout << sub_string.size() << "\n";


	return 0;
}