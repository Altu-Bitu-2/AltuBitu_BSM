#include <iostream>
#include <vector>

using namespace std;

struct info { //�������� �κ� ���� ����
    int power;  //������
    bool is_on; // �κ� �ִ��� ������
};

vector<info> belt;  //�����̳� ��Ʈ ����(������, �κ� ����)
int zero_power;     //�������� 0�� ��Ʈ ĭ�� ����

int minusPosition(int n, int pos) { //�ε��� ����
    if (--pos >= 0) {   //���������� ȸ�� -> �ڸ��� 1 ����
        return pos;
    }
    return n * 2 - 1;   //���� ���� ��� +2n ���༭ 2n - 1
}

void second(int n, int start, int end) {    //2�ܰ�
    int cur = end;
    while (cur != start) { //end - 1 ���� start ���� �˻�
        cur = minusPosition(n, cur);
        int next = (cur + 1) % (n * 2); //���� ��ġ
        if (belt[cur].is_on && !belt[next].is_on && belt[next].power) { //���� ��ġ�� �κ��� �ְ�, ���� ��ġ�� �κ��� ������ ������ 1�̻��� ��� -> �κ� �ű�
            belt[cur].is_on = false;    //�κ� ����
            belt[next].power--;     //�κ� �Ű��� ��Ʈ ������ 1 ����
            if (next != end) { //������ ��ġ �ƴ� ��츸
                belt[next].is_on = true; //�κ� �ű��
            }
            if (belt[next].power == 0) {    //������ 0�� ���
                zero_power++;   //������ 0�� ��Ʈ �� 1 ����
            }
        }
    }
}

void third(int start) { //3�ܰ�
    if (belt[start].power) { //�ø��� ��ġ�� �������� 0�� �ƴ϶�� �κ� �ä���
        belt[start].is_on = true;   //���� ��Ʈ�� �κ� ������
        belt[start].power--;        //������ 1 ����
        if (belt[start].power == 0) {   //�������� 0�� ���
            zero_power++;   //�������� 0�� �κ� ���� 1 ����
        }
    }
}

/**
 * [�����̾� ��Ʈ ���� �κ� ����]
 * 1. ��Ʈ�� �� ĭ ���� �κ��� �Բ� �� ĭ ȸ��
 * 2. ���� ���� ��Ʈ�� �ö� �κ�����, ��Ʈ ȸ�� �������� �� ĭ �̵��� �� �ִٸ� �̵� (�̵�����: �̵��Ϸ��� ĭ�� �κ��� ����, �� ĭ�� �������� 1 �̻��̾�� ��)
 * 3. �ø��� ��ġ�� �ִ� ĭ�� �������� 0�� �ƴϸ� �ø��� ��ġ�� �κ� �ø�
 * 4. �������� 0�� ĭ�� ������ k�� �̻��̶�� ���� ����. �׷��� �ʴٸ� 1�� ���ư�
 * -> 1 ~ 3������ 1�ܰ�
 *
 * [���� Ǯ��]
 * ��Ʈ�� �κ��� �ű�� �� �ƴ϶�, �ø��� ��ġ�� ������ ��ġ�� �ε��� ���� �ٲ㼭 ����
 * �ʿ��� �����̳�: �������� �κ��� ���翩�θ� üũ�� �迭
 *
 * 1��: ��Ʈ�� ������ �������̹Ƿ�, ��Ʈ �� ĭ ȸ�� �� �ø��� ��ġ�� ������ ��ġ�� �ε��� ���� �ϳ� ����
 * 2��: ���� ���� �ö� �κ����� ����ؾ� �ϹǷ� (������ ��ġ - 1)���� (�ø��� ��ġ)���� �˻� -> �κ� �ű�� �� �����ϸ� ���翩�� üũ�ϰ� ������ ����
 * 3��: �ø��� ��ġ ĭ ������ 0�� �ƴ϶�� �ش� ĭ �κ� ���� ���� üũ + ������ ����
 *
 * �ش� ������ deque �ڷᱸ���� ����ؼ��� ���� ���� (1������ ȸ���ϴ� �κи� �ٸ��� 2��, 3���� ������ ����)
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    //�Է�
    cin >> n >> k;
    belt.assign(n * 2, { 0, false });
    for (int i = 0; i < n * 2; i++) {
        cin >> belt[i].power;
    }

    //����
    int start = 0;    //�ø��� ��ġ
    int end = n - 1;  //������ ��ġ
    int step = 0;     //�ܰ� ��
    while (true) {
        start = minusPosition(n, start);    //���������� ȸ�� �� �ٲ�� start����
        end = minusPosition(n, end);        //���������� ȸ�� �� �ٲ�� end����
        if (belt[end].is_on) { //��Ʈ ȸ�� ��, �κ��� ������ ��ġ�� �ִٸ� ������
            belt[end].is_on = false;    //�κ� �������ϱ� false�� �ٲٱ�
        }
        second(n, start, end);  //2
        third(start);   //3
        step++;     //�ܰ� �� ����
        if (zero_power >= k) {  //������ 0�� k������ Ŀ����
            break;  //����
        }
    }

    //���
    cout << step;
    return 0;
}