
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

//그라운드에 있는 카드를 덱으로 옮기는 함수
void moveCard(deque<int>& deck, deque<int>& ground) {
    while (!ground.empty()) {   //그라운드에 카드가 있는 경우 없을때까지
        deck.push_back(ground.back());  //그라운드의 카드를 뒤에서부터 덱의 뒤에 넣는다.
        ground.pop_back();  //그라운드의 카드 제거
    }
}

//게임을 진행하는 함수
pair<int, int> playGame(int m, vector<deque<int>>& deck, vector<deque<int>>& ground) {
    bool turn = false; //도도부터 시작

    while (m--) {
        //이번 턴의 사람이 카드 뒤집어서 그라운드에 올려놓기
        int card = deck[turn].front();  //내 차례인 경우 덱의 맨 앞부분 카드 그라운드로 옮기기
        ground[turn].push_front(card);  //그라운드로 카드 옮기기
        deck[turn].pop_front();     //덱 카드 제거

        if (deck[turn].empty()) {       //덱이 비었을 경우 경기 종료
            break;  
        }

        //이번에 종을 칠 사람
        int bell = -1;
        if (card == 5) {    //5인 카드가 나올 경우 벨을 눌러야됨
            bell = 0;
        }
        else if (!ground[0].empty() && !ground[1].empty() && (card + ground[!turn].front() == 5)) {
            bell = 1;   //두 그라운드 모두 비지 않았고 그라운드 맨 위 카드의 합이 5인 경우
        }

        if (bell != -1) {   //벨을 누르는 경우
            moveCard(deck[bell], ground[!bell]);    //상대 그라운드의 카드 가져오기
            moveCard(deck[bell], ground[bell]);     //내 그라운드의 카드 가져오기
        }
        turn = !turn; //차례 바꾸기
    }
    return make_pair(deck[0].size(), deck[1].size());   //각자 남은 덱의 카드 수가 많을 수록 이김
}

/**
 * [숫자 할리갈리 게임] - 시뮬레이션 문제
 * - 카드 덱과 그라운드의 카드를 관리하기 위해 덱 사용
 *
 * 1. 차례가 되면, 상단 카드를 그라운드에 놓는다.
 * 2. 누군가의 카드 덱이 비는 즉시 게임 종료
 * 3. 종을 치면, 상대방의 그라운드 카드를 뒤집어서 카드 더미의 밑에 넣는다.
 */

int main() {
    int n, m, num1, num2;
    vector<deque<int>> deck(2), ground(2);

    cin >> n >> m;  //카드 갯수, 게임 진행 횟수
    while (n--) {
        cin >> num1 >> num2;    //각자 카드가 덱의 맨 아래부터 입력
        deck[0].push_front(num1);   //도도 카드덱
        deck[1].push_front(num2);   //수연 카드덱
    }

    pair<int, int> result = playGame(m, deck, ground);  //경기 결과를 저장하는 pair

    if (result.first == result.second) {    //남은 카드의 수가 같아서 비긴경우
        cout << "dosu\n";
    }
    else if (result.first > result.second) {    //도도의 남은 카드의 수가 더 많은 경우
        cout << "do\n";
    }
    else if (result.first < result.second) {    //수연의 남은 카드의 수가 더 많은 경우
        cout << "su\n";
    }
    return 0;
}
