#include <iostream>
#include <vector>

using namespace std;

bool isGroup(string str) {
    char cur = NULL; //������ ����
    vector<bool> alphabet(26, false); //�� ���ĺ��� ���� ���θ� üũ

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == cur) { //�����ؼ� ��Ÿ�� ����
            continue;   //�����ؼ� ���ڰ� ��Ÿ�� ��� continue
        }
        //������ ���ڿ� �ٸ� ���ڰ� ��Ÿ���� ��
        if (alphabet[str[i] - 'a']) { //������ �����ߴ� ���ڸ� �������� ��Ÿ�� ��
            return false;   //������ ������ �����̸� alphabet�� true �� ����
        }
        cur = str[i];       //���� ���ڷ� �ٲ㼭 ���� i���� ���� �����ؼ� �������� Ȯ��
        alphabet[str[i] - 'a'] = true;  //�����ϴ� ���� true�� �ٲٱ�
    }
    return true;    
}

/**
 * [�׷� �ܾ� üĿ] - �ܼ� ���� ����
 * - �̹� ������ ���ĺ��� �迭�� �ε���(���ĺ�)�� Ȱ���ؼ� ���� true/false�� ����
 * - set���� üũ�� ���� �ְ����� �˻�, ���� �ø��� O(logN)�� �ð����⵵�� �ɸ��Ƿ� �ε��� ������ ������ �迭�� ȿ����
 * - ó�� �����ϴ� ���ĺ��� �迭 ���� ������Ʈ �ϰ�, �������� �������µ� �̹� ������ ���ĺ��̸� �׷� �ܾ �ƴϴ�.
 */

int main() {
    int n, result = 0;  

    //�Է�
    cin >> n;
    while (n--) {
        string word;
        cin >> word;

        //����
        if (isGroup(word)) { //�׷� �ܾ����� Ȯ��
            result++;       //isGroup �� true�� ���� ��� result �� �����ؼ� count
        }
    }

    //���
    cout << result;
    return 0;
}