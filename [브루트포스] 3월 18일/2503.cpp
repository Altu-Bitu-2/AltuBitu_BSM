#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;  //��Ʈ����ũ�� �� ������ ��� pair

struct baseball {
    string num;       //���� �ٸ� �� �ڸ� ��
    int strike, ball; //��Ʈ����ũ ����, �� ����
};

ci cntStrikeBall(string& s1, string& s2) {  //s1�� s2�� ���� ��Ʈ����ũ�� �� ������ �����ϴ� �Լ�
    int strike_cnt = 0; //s1�� s2������ strike ����
    int ball_cnt = 0;   //s1�� s2������ ball ����

    for (int i = 0; i < 3; i++) {
        if (s1[i] == s2[i]) { //��ġ+�� ��Ȯ�� ��ġ -> ��Ʈ����ũ
            strike_cnt++;   //��Ʈ����ũ �� ����
        }
        else if (s1.find(s2[i]) != s1.npos) { //��ġ �ٸ��� ���� ���� -> ��
            ball_cnt++; //�� �� ����
        }
    }

    return ci(strike_cnt, ball_cnt);   
}


//������ ���� ����
int game(int n, vector<baseball>& question) {
    int ans = 0; //���� ����

    for (int i = 123; i <= 987; i++) {  //123���� 987���� �θ�Ʈ����
        bool check = true;      //
        string s1 = to_string(i);  //�������� Ȯ���� ��

        if (s1[0] == '0' || s1[1] == '0' || s1[2] == '0') { //0�� �ϳ��� �ִٸ�
            continue;       //0�� �������� �����Ƿ� ó���ʰ� continue�� �Ѿ
        }
        if (s1[0] == s1[1] || s1[0] == s1[2] || s1[1] == s1[2]) { //���� ���� �� �ϳ��� �ִٸ�
            continue;       // ���� �� ������ �ȵǹǷ� ó������ �ʰ� continue�� �Ѿ
        }

        for (int j = 0; j < n; j++) {
            string s2 = question[j].num; //�������� ���� ��
            ci cnt = cntStrikeBall(s1, s2); //s1�� s2������ ��Ʈ����ũ�� �� ����
            if (cnt.first != question[j].strike || cnt.second != question[j].ball) { //�ϳ��� �ٸ���
                check = false;  //check�� false��  for �� ������ ���� i����
                break;
            }
        }

        if (check) {    //������ ���� �� ���
            ans++;
        }
    }

    return ans;
}

/**
 * [���� �߱�]
 * ���� �ٸ� �� �ڸ� ������ ��ġ + �� ������ ��Ʈ����ũ, ��ġ�� �ٸ��� ���� �����ϸ� ��
 * n���� �������� ���� ��Ʈ����ũ�� �� ������ �־��� ��, �̸� ��� �����ϴ� ���� �ٸ� �� �ڸ� ���� ���� ����
 *
 * [Ǯ��]
 * ���� �ٸ� �� �ڸ����� 123 ~ 987�� �����ϴ�. �̴� �� 865����
 * ���� n�� ������ �ִ� 100
 * ���� 123���� �ϳ��� ������Ű�� ������ �Ǵ��� �˻��ص� 865 * 100 * 3(�ڸ���)���� ���� ����� ����!
 */

int main() {
    int n;  //������ ��

    //�Է�
    cin >> n;   

    vector<baseball> question(n);   //baseball����ü n���� ������ ����
    for (int i = 0; i < n; i++) {   //question�� ����, strike����, ball���� �Է�
        cin >> question[i].num >> question[i].strike >> question[i].ball;
    }

    //���� + ���
    cout << game(n, question);

    return 0;
}