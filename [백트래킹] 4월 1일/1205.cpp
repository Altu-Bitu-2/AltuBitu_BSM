#include <iostream>
#include <vector>

using namespace std;

int findRanking(int n, int new_score, int p, vector<int>& ranking) {
    int idx = 1;    //��ŷ1 ����
    int ans = 1;
    //���ο� ������ ��� ��ġ�� ������ Ž��
    while (idx <= n) {
        if (new_score > ranking[idx]) { //�� ������ ��ŷ�� idx�κ� �������� ū ���
            break;  
        }
        if (new_score < ranking[idx]) { //���� ��ŷ�� �������� ���� �������
            ans = idx + 1;      //���� ��ŷ 
        }
        idx++;  //���� ��ŷ
    }
    if (idx == p + 1) { //��ŷ ����Ʈ�� ���� ���ϴ� ���
        return -1;  //-1 ����
    }
    return ans; //��� ����
}

/**
 * [��� ���ϱ�]
 *
 * 1. n = 0�� ��, ���
 * 2. ����� p���� ������, ������ �� ���� ���� ��ŷ�� ���ŵǹǷ� ��ŷ ����Ʈ�� ���� ���ϴ� ��� ��� (����)
 *
 * ���� ��ŷ�� �ö� n���� ����� ���ο� ������ ���ϸ� ���ο� ���� �� ������ ���
 * ���ο� ������ ���� Ž�� ����� �������� �۴ٸ� -> ���� Ž�� ��� + 1
 * ������ ��� -> �� �� ��� �״�� ��� -> �ƹ� ó���� ���� ����!
 */

int main() {
    int n, new_score, p;

    //�Է�
    cin >> n >> new_score >> p;
    vector<int> ranking(p + 1, 0);  
    for (int i = 1; i <= n; i++) {
        cin >> ranking[i];  //��ŷ�� ���� �Է�
    }

    //���� & ���
    cout << findRanking(n, new_score, p, ranking);  
    return 0;
}