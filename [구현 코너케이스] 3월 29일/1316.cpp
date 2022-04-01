#include <iostream>
#include <vector>

using namespace std;

bool isGroup(string str) {
    char cur = NULL; //현재의 문자
    vector<bool> alphabet(26, false); //각 알파벳의 등장 여부를 체크

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == cur) { //연속해서 나타난 문자
            continue;   //연속해서 문자가 나타난 경우 continue
        }
        //이전의 문자와 다른 문자가 나타났을 때
        if (alphabet[str[i] - 'a']) { //이전에 등장했던 문자면 떨어져서 나타난 것
            return false;   //이전에 등장한 문자이면 alphabet이 true 가 나옴
        }
        cur = str[i];       //현재 문자로 바꿔서 다음 i에서 문자 연속해서 나오는지 확인
        alphabet[str[i] - 'a'] = true;  //존재하는 문자 true로 바꾸기
    }
    return true;    
}

/**
 * [그룹 단어 체커] - 단순 구현 문제
 * - 이미 등장한 알파벳을 배열의 인덱스(알파벳)를 활용해서 정보 true/false로 저장
 * - set으로 체크할 수도 있겠지만 검색, 삽입 시마다 O(logN)의 시간복잡도가 걸리므로 인덱스 접근이 가능한 배열이 효율적
 * - 처음 등장하는 알파벳은 배열 정보 업데이트 하고, 무리에서 떨어졌는데 이미 등장한 알파벳이면 그룹 단어가 아니다.
 */

int main() {
    int n, result = 0;  

    //입력
    cin >> n;
    while (n--) {
        string word;
        cin >> word;

        //연산
        if (isGroup(word)) { //그룹 단어인지 확인
            result++;       //isGroup 이 true가 나올 경우 result 값 증가해서 count
        }
    }

    //출력
    cout << result;
    return 0;
}