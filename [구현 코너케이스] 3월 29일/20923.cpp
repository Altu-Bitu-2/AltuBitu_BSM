
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

//�׶��忡 �ִ� ī�带 ������ �ű�� �Լ�
void moveCard(deque<int>& deck, deque<int>& ground) {
    while (!ground.empty()) {   //�׶��忡 ī�尡 �ִ� ��� ����������
        deck.push_back(ground.back());  //�׶����� ī�带 �ڿ������� ���� �ڿ� �ִ´�.
        ground.pop_back();  //�׶����� ī�� ����
    }
}

//������ �����ϴ� �Լ�
pair<int, int> playGame(int m, vector<deque<int>>& deck, vector<deque<int>>& ground) {
    bool turn = false; //�������� ����

    while (m--) {
        //�̹� ���� ����� ī�� ����� �׶��忡 �÷�����
        int card = deck[turn].front();  //�� ������ ��� ���� �� �պκ� ī�� �׶���� �ű��
        ground[turn].push_front(card);  //�׶���� ī�� �ű��
        deck[turn].pop_front();     //�� ī�� ����

        if (deck[turn].empty()) {       //���� ����� ��� ��� ����
            break;  
        }

        //�̹��� ���� ĥ ���
        int bell = -1;
        if (card == 5) {    //5�� ī�尡 ���� ��� ���� �����ߵ�
            bell = 0;
        }
        else if (!ground[0].empty() && !ground[1].empty() && (card + ground[!turn].front() == 5)) {
            bell = 1;   //�� �׶��� ��� ���� �ʾҰ� �׶��� �� �� ī���� ���� 5�� ���
        }

        if (bell != -1) {   //���� ������ ���
            moveCard(deck[bell], ground[!bell]);    //��� �׶����� ī�� ��������
            moveCard(deck[bell], ground[bell]);     //�� �׶����� ī�� ��������
        }
        turn = !turn; //���� �ٲٱ�
    }
    return make_pair(deck[0].size(), deck[1].size());   //���� ���� ���� ī�� ���� ���� ���� �̱�
}

/**
 * [���� �Ҹ����� ����] - �ùķ��̼� ����
 * - ī�� ���� �׶����� ī�带 �����ϱ� ���� �� ���
 *
 * 1. ���ʰ� �Ǹ�, ��� ī�带 �׶��忡 ���´�.
 * 2. �������� ī�� ���� ��� ��� ���� ����
 * 3. ���� ġ��, ������ �׶��� ī�带 ����� ī�� ������ �ؿ� �ִ´�.
 */

int main() {
    int n, m, num1, num2;
    vector<deque<int>> deck(2), ground(2);

    cin >> n >> m;  //ī�� ����, ���� ���� Ƚ��
    while (n--) {
        cin >> num1 >> num2;    //���� ī�尡 ���� �� �Ʒ����� �Է�
        deck[0].push_front(num1);   //���� ī�嵦
        deck[1].push_front(num2);   //���� ī�嵦
    }

    pair<int, int> result = playGame(m, deck, ground);  //��� ����� �����ϴ� pair

    if (result.first == result.second) {    //���� ī���� ���� ���Ƽ� �����
        cout << "dosu\n";
    }
    else if (result.first > result.second) {    //������ ���� ī���� ���� �� ���� ���
        cout << "do\n";
    }
    else if (result.first < result.second) {    //������ ���� ī���� ���� �� ���� ���
        cout << "su\n";
    }
    return 0;
}
