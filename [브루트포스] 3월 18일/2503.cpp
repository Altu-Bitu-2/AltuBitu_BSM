#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;  //스트라이크와 볼 갯수를 담는 pair

struct baseball {
    string num;       //서로 다른 세 자리 수
    int strike, ball; //스트라이크 개수, 볼 개수
};

ci cntStrikeBall(string& s1, string& s2) {  //s1과 s2에 대한 스트라이크와 볼 갯수를 리턴하는 함수
    int strike_cnt = 0; //s1과 s2사이의 strike 개수
    int ball_cnt = 0;   //s1과 s2사이의 ball 개수

    for (int i = 0; i < 3; i++) {
        if (s1[i] == s2[i]) { //위치+수 정확히 일치 -> 스트라이크
            strike_cnt++;   //스트라이크 수 증가
        }
        else if (s1.find(s2[i]) != s1.npos) { //위치 다른데 수가 존재 -> 볼
            ball_cnt++; //볼 수 증가
        }
    }

    return ci(strike_cnt, ball_cnt);   
}


//가능한 답의 갯수
int game(int n, vector<baseball>& question) {
    int ans = 0; //정답 개수

    for (int i = 123; i <= 987; i++) {  //123부터 987까지 부르트포스
        bool check = true;      //
        string s1 = to_string(i);  //정답인지 확인할 수

        if (s1[0] == '0' || s1[1] == '0' || s1[2] == '0') { //0이 하나라도 있다면
            continue;       //0은 포함하지 않으므로 처리않고 continue로 넘어감
        }
        if (s1[0] == s1[1] || s1[0] == s1[2] || s1[1] == s1[2]) { //서로 같은 수 하나라도 있다면
            continue;       // 같은 수 있으면 안되므로 처리하지 않고 continue로 넘어감
        }

        for (int j = 0; j < n; j++) {
            string s2 = question[j].num; //질문으로 들어온 수
            ci cnt = cntStrikeBall(s1, s2); //s1과 s2사이의 스트라이크와 볼 개수
            if (cnt.first != question[j].strike || cnt.second != question[j].ball) { //하나라도 다르면
                check = false;  //check는 false로  for 문 나가고 다음 i수로
                break;
            }
        }

        if (check) {    //가능한 답의 수 계산
            ans++;
        }
    }

    return ans;
}

/**
 * [숫자 야구]
 * 서로 다른 세 자리 수에서 위치 + 수 같으면 스트라이크, 위치는 다르고 수가 존재하면 볼
 * n개의 질문으로 수와 스트라이크와 볼 개수가 주어질 때, 이를 모두 만족하는 서로 다른 세 자리 정답 수의 개수
 *
 * [풀이]
 * 서로 다른 세 자리수는 123 ~ 987이 가능하다. 이는 총 865가지
 * 질문 n의 범위는 최대 100
 * 따라서 123부터 하나씩 증가시키며 정답이 되는지 검사해도 865 * 100 * 3(자릿수)으로 접근 충분히 가능!
 */

int main() {
    int n;  //질문의 수

    //입력
    cin >> n;   

    vector<baseball> question(n);   //baseball구조체 n개를 가지는 벡터
    for (int i = 0; i < n; i++) {   //question에 숫자, strike갯수, ball갯수 입력
        cin >> question[i].num >> question[i].strike >> question[i].ball;
    }

    //연산 + 출력
    cout << game(n, question);

    return 0;
}