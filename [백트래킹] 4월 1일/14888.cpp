#include <iostream>
#include <vector>

using namespace std;
const int INF_MAX = 1e9;
const int SIZE = 11;    //가능한 수열 최대크기

int n;
vector<int> num(SIZE + 1);
vector<int> expression(4); //0: +, 1: -, 2: *, 3: /
int max_value = -INF_MAX, min_value = INF_MAX;  //최대값과 최소값 초기화,
// 연산 시 주어진 값과 비교해서 최대값, 최소값이 변할꺼니까 max_value는 가능한 가장 작은 값,
//min_value는 가능한 가장 큰 값으로 초기화

void backtracking(int cnt, int sum) { //cnt: 수 인덱스, sum: 연산 결과
    if (cnt == n - 1) { //연산 모두 완료했다면 (기저조건), recursive function에서 멈추는 포인트
        max_value = max(max_value, sum);    //최소값 바꾸기
        min_value = min(min_value, sum);
        return;
    }
    for (int i = 0; i < 4; i++) { //연산자 검사
        if (expression[i]) {    //연산 있으면
            expression[i]--;    //연산 1회 했으니까 연산자 한개 빼기
            int new_sum = 0;
            switch (i) { //연산자 종류에 따라
            case 0: // 0: + 연산
                new_sum = sum + num[cnt + 1];
                break;
            case 1: //1 : - 연산
                new_sum = sum - num[cnt + 1];
                break;
            case 2: //2: * 연산
                new_sum = sum * num[cnt + 1];
                break;
            case 3: //3: / 연산
                new_sum = sum / num[cnt + 1];
                break;
            }
            backtracking(cnt + 1, new_sum); //다음 인덱스 연산
            expression[i]++;
        }
    }
}

/**
 * 연산자 모두 돌려보면서 배치한 후, 각 연산자에 따른 값 계산
 */

int main() {
    //입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> expression[i];
    }

    //연산
    backtracking(0, num[0]);

    //출력
    cout << max_value << '\n' << min_value;
    return 0;
}