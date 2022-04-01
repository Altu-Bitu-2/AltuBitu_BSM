#include <iostream>
#include <vector>

using namespace std;

vector<int> findPattern(int num) {  //일의 자리 패턴을 구하는 함수
    vector<int> pattern = { num };

    int temp = num;
    while (num != (temp * num) % 10) {  //거듭제곱 계산 시 일의 자리가 처음의 수와 같아질 때까지 반복
        temp *= num;
        temp %= 10;
        pattern.push_back(temp);    //구한 일의 자리를 패턴 벡터에 저장한다.
    }
    return pattern; //일의 자리가 처음 수와 같아진 경우 패턴을 찾은 것이니까 리턴
}

/**
 * [분산처리]
 *
 * - a^b의 일의 자리를 구하는 문제
 * - 일의 자리는 0 ~ 9 중 하나 이므로, 어떤 수를 계속 곱해 나가면 일의 자리는 패턴을 가지게 되어 있음
 *     ex) 2 -> 4 -> 8 -> 6 -> 2 ...
 * - 0 ~ 9까지 일의 자리 패턴을 미리 구한 후, a의 일의 자리에 대한 (b - 1 % 패턴의 길이)번째 수를 출력하면 된다.
 * - 0이 나올 경우 10번 컴퓨터가 처리하므로, 0이 출력되지 않도록 예외처리
 */

int main() {
    int t, a, b;    //t: 테스트 케이스, a ^ b

    //0 ~ 9까지 일의 자리 패턴 미리 구하기
    vector<vector<int>> last_digit(10, vector<int>(0));     //각 패턴을 저장할 벡터
    vector<int> pattern_size(10, 1);
    for (int i = 0; i < 10; i++) {
        last_digit[i] = findPattern(i);     //패턴 계산 후 저장
        pattern_size[i] = last_digit[i].size();     //패턴의 크기 저장
    }

    //입력
    cin >> t;
    while (t--) {   //테스트 케이스가 끝날 때까지
        cin >> a >> b;
        a %= 10;    //a ^ b의 a의 1의 자리 구하기

        if (a == 0) {   //1의 자리가 0인 경우 예외처리
            cout << "10\n";
            continue;
        }
        //인덱스가 0부터 시작하므로 (b - 1)로 계산해야 함을 주의
        cout << last_digit[a][(b - 1) % pattern_size[a]] << '\n';
    }
    return 0;
}