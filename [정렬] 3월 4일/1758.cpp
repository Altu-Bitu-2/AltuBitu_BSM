#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

long long calTip(int n, vector<int>& tips) {    //���� ����ϴ� �Լ�
    long long ans = 0;                    //���� �� ��
    for (int i = 0; i < n; i++) {       //��ü ���� ���ؼ� �� ���
        int cur_tip = tips[i] - i;      //���� �ַ��ߴ� �� -(���� ��� - 1)
        if (cur_tip < 0) //������ ���� ������ �ʴµ� ó���� �������� ���������Ƿ� �ƿ� break
            break;      
        ans += cur_tip;     //���� ���� ���� ����� ���� ���Ѵ�
    }
    return ans;     // ��ü �� ���� ����
}

/**
 * ��ȣ�� ���� �� �ִ� ���� �ִ��� �Ƿ��� ���� ���� ����� ������ ���ƾ���
 * !����! �־����� N�� �ִ� ũ�Ⱑ 100,000�̰� ���� �ִ� ũ�Ⱑ 100,000�̹Ƿ�
 *       ������ �ִ��� 10^5 * (10^5+1) / 2�� int ������ �ѱ� ������ long long �� ��� ��
 */

int main() {        //�����Լ�
    int n;          //���� ��

    //�Է�
    cin >> n;       //�� �� �Է¹ޱ�
    vector<int> tips(n, 0);        //�� ���� n���,  0���� �ʱ�ȭ
    for (int i = 0; i < n; i++) {   //��ü ���� ����
        cin >> tips[i];             //�� �Է¹ޱ�
    }
    //����
    sort(tips.begin(), tips.end(), greater<>()); //�������� ����
    //���
    cout << calTip(n, tips) << '\n';        //�� ���
    return 0;
}