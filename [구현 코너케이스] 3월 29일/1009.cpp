#include <iostream>
#include <vector>

using namespace std;

vector<int> findPattern(int num) {  //���� �ڸ� ������ ���ϴ� �Լ�
    vector<int> pattern = { num };

    int temp = num;
    while (num != (temp * num) % 10) {  //�ŵ����� ��� �� ���� �ڸ��� ó���� ���� ������ ������ �ݺ�
        temp *= num;
        temp %= 10;
        pattern.push_back(temp);    //���� ���� �ڸ��� ���� ���Ϳ� �����Ѵ�.
    }
    return pattern; //���� �ڸ��� ó�� ���� ������ ��� ������ ã�� ���̴ϱ� ����
}

/**
 * [�л�ó��]
 *
 * - a^b�� ���� �ڸ��� ���ϴ� ����
 * - ���� �ڸ��� 0 ~ 9 �� �ϳ� �̹Ƿ�, � ���� ��� ���� ������ ���� �ڸ��� ������ ������ �Ǿ� ����
 *     ex) 2 -> 4 -> 8 -> 6 -> 2 ...
 * - 0 ~ 9���� ���� �ڸ� ������ �̸� ���� ��, a�� ���� �ڸ��� ���� (b - 1 % ������ ����)��° ���� ����ϸ� �ȴ�.
 * - 0�� ���� ��� 10�� ��ǻ�Ͱ� ó���ϹǷ�, 0�� ��µ��� �ʵ��� ����ó��
 */

int main() {
    int t, a, b;    //t: �׽�Ʈ ���̽�, a ^ b

    //0 ~ 9���� ���� �ڸ� ���� �̸� ���ϱ�
    vector<vector<int>> last_digit(10, vector<int>(0));     //�� ������ ������ ����
    vector<int> pattern_size(10, 1);
    for (int i = 0; i < 10; i++) {
        last_digit[i] = findPattern(i);     //���� ��� �� ����
        pattern_size[i] = last_digit[i].size();     //������ ũ�� ����
    }

    //�Է�
    cin >> t;
    while (t--) {   //�׽�Ʈ ���̽��� ���� ������
        cin >> a >> b;
        a %= 10;    //a ^ b�� a�� 1�� �ڸ� ���ϱ�

        if (a == 0) {   //1�� �ڸ��� 0�� ��� ����ó��
            cout << "10\n";
            continue;
        }
        //�ε����� 0���� �����ϹǷ� (b - 1)�� ����ؾ� ���� ����
        cout << last_digit[a][(b - 1) % pattern_size[a]] << '\n';
    }
    return 0;
}