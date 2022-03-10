#include <iostream>

using namespace std;

#define day 86400 //하루 = 86400초



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);


	int h, m, s, q, x, f, b;
	cin >> h >> m >> s >> q;		//현재 시간

	int cur_time = 3600 * h + 60 * m + s;	//현재 시간을 초로 표시


	for (int i = 0; i < q; i++) {
		cin >> x;
		if (x == 3)
			cout << cur_time / 3600 << ' ' << (cur_time / 60) % 60 <<
			' ' << cur_time % 60 << '\n';		//endl쓰면 시간초과남 무조건 '\n'쓰자
		else if (x == 1) {
			cin >> f;
			cur_time = (cur_time + f) % day;
		}
		else {
			cin >> b;
			cur_time = (cur_time - b) % day;

			while (cur_time < 0) {		//현재 시간이 음수가 되는 경우
				cur_time += day;
			}
		}
	}


	return 0;
}
	
