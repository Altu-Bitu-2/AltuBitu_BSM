#include <iostream>
#include <vector>
#include <algorithm>    //prev_permutation �̿�

using namespace std;

//prev_permutation()�� Ȱ���� ������ �̿��� Ǯ��
int blackJackC(int n, int m, vector<int>& card) {   //n:ī���� ����, m: ����������ϴ� ��,  card: ī�庤��
    int ans = 0; //����

    vector<bool> is_selected(n, false); //�� ī�尡 true   ���� ���ο� ����  vector
    for (int i = 0; i < 3; i++) { //3�� ī�� �� ������ �ʱ�ȭ
        is_selected[i] = true;  
    }

    do {
        int sum = 0; //�� 3���� ī�� �� ����
        for (int i = 0; i < n; i++) {
            if (is_selected[i]) {   //true�� ���õ� 3���� ī�� �� ���
                sum += card[i];     //3���� ī�� ���� sum �� ����
            }
        }
        //m�� ���� ����� ī�� ���ϱ�
        if (sum <= m) { 
            ans = max(ans, sum);    //���� ans�� ���Ͽ� ���� ū ���� ans�� ����
        }
    } while (prev_permutation(is_selected.begin(), is_selected.end())); //3���� true�� �ִ� ��ü ��츦 �ݺ�
    return ans;  //�� ����
}

//3�� for�� Ǯ��
int blackJackFor(int n, int m, vector<int>& card) {
    int ans = 0; //����

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {   //��ü ī�忡�� 3�� �����ϴ� ��ü ��츦 3�� for������ ����
                int sum = card[i] + card[j] + card[k];
                if (sum > m) { //m�� �Ѿ��ٸ�
                    break; //(�����غ�����) �ٷ� return ans; �� �ϸ� ��� �ɱ��?
                            // m�� �� ������� �� �ִ� ��찡 ������� ���� �� ����
                }
                ans = max(ans, sum);    //���� ���� ���� ���� �� �� �� ū �� ����
            }
        }
    }
    return ans;
}

/**
 * [ ���� ] - �ܼ� ����
 * ī�尡 �ִ� 100���̹Ƿ�,
 * C(100, 3) < 100*100*100 = 1,000,000 -> ���Ʈ���� ����� ����
 *
 * ver1. 3�� for�� �̿��ؼ� ����
 * +) �ڵ��� ȿ������ ���̱� ����, ī�带 ������ �����Ͽ� M�� �Ѿ�� ���� �ݺ� ���� (�̶�, �� �ݺ��� ���������� �� ����!)
 *
 * ver2. prev_permutation()�� Ȱ���Ͽ� ��� ������ ���ؼ� ����
 */

int main() {
    int n, m;   //n: ī���� ����, m: �� ī���� ���� ������ �� ��

    //�Է�
    cin >> n >> m;  
    vector<int> card(n, 0); //�ٴڿ� ���� ī�忡 ���� vector, 0���� �ʱ�ȭ
    for (int i = 0; i < n; i++) {   
        cin >> card[i];     // card���Ϳ� �Է�
    }   

    //����
    //���� Ǯ��
    int ans = blackJackC(n, m, card);   

    //3�� for �� Ǯ��
    //sort(card.begin(), card.end());
    //int ans = blackJackFor(n, m, card);

    //���
    cout << ans;
    return 0;
}