
#include <iostream>
#include <string>
#include <map>

using namespace std;


int main() {

	int n;		//파일 갯수
	cin >> n;

	string filename, extension;
	map<string, int> ext_n;		//확장자


	for (int i = 0; i < n; i++) {
		cin >> filename;

		int dot = filename.rfind(".");

		extension = filename.substr(dot + 1);

		ext_n[extension] += 1;

		
	}

	for (auto iter = ext_n.begin(); iter != ext_n.end(); iter++) {
		cout <<  iter->first << ' ' << iter->second << "\n";
	}
	
}