#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e8;

vector<bool> visited; //�湮 �˻� �迭
vector<vector<int>> matrix; //��� ���
int n, ans = INF; //�ּ� ��� ���� ���� �̸� �ִ����� �ʱ�ȭ

/**
 * !�����غ���! �Լ��� �� ���ڴ� ���� � ������ �ϰ� �ֳ���?
 * cnt: �湮�� ������ ��
 * cur_city: ���� �湮 ����
 * cost: 
 */
void backtracking(int cnt, int cur_city, int cost) {
    if (cost >= ans) { //�����غ��� : �� ���ǹ��� ������ ��� �ɱ��?
        return;
    }
    if (cnt == n) { //���� ���� : n���� ���ø� ��ȸ����
        //��� ����(0)�� �ٽ� ���ƿ� �� �ִ��� Ȯ��
        if (matrix[cur_city][0] != 0) { //0�� �ƴ� ��� �̵� ����
            ans = min(ans, cost + matrix[cur_city][0]);     //���� �ּҺ��� ���� ��뿡�� 0�����÷� ���ư��� ���
            //���� �� �� �� �ּ� ��� ����
        }
        return;
    }
    for (int i = 0; i < n; i++) { //cur_city���� ���� i�� �̵�
        if (matrix[cur_city][i] && !visited[i]) { //���� �ְ�, ���� �湮���� ���� ����
            visited[i] = true;  //�湮 ǥ��
            backtracking(cnt + 1, i, cost + matrix[cur_city][i]);
            visited[i] = false; //�湮���� ���󺹱�
        }
    }
}

/**
 * ��Ʈ��ŷ Ǯ�� (4ms)
 *
 * �� ����Ŭ�� �����, ��� ���ÿ��� �����ϵ� ���� �����Ƿ� 0�� ���ú��� �����ϴ� ��츸 �˻��ϸ� �ȴ�.
 */

int main() {
    //�Է�
    cin >> n;
    visited.assign(n, false);   //n�� ���� �̹湮���� �ʱ�ȭ
    matrix.assign(n, vector<int>(n, 0)); //n by n matrix 0���� �ʱ�ȭ
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];    //matrix ��� ��� �Է�
        }
    }

    //����
    visited[0] = true; //0������ �湮
    backtracking(1, 0, 0);      //0������ �湮, �湮�� ���� 1, ���� ��� 0

    //���
    cout << ans;
    return 0;
}