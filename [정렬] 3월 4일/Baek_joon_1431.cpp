
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//문자열의 모든 자릿수 합을 구하는 함수
int sumNum(string str) {        
    int sum = 0;            //합을 넣을 변수 num
    for (int i = 0; i < str.size(); i++) {      //str의 글자수만큼
        if (isdigit(str[i])) { //문자(char)에 대해 숫자인지 판별하는 함수
            sum += str[i] - '0'; //char -> int로 바꾸는 방법 (아스키 코드에 대해 알아보세요)
        }
    }
    return sum;
}

//비교함수
bool cmp(const string& s1, const string& s2) {
    if (s1.size() != s2.size()) { //두 문자열의 길이가 다르다면 짧은 문자열이 먼저 오도록
        return s1.size() < s2.size();   //문자열 길이에 대해 오름차순으로 정렬
    }
    if (sumNum(s1) != sumNum(s2)) { //두 문자열의 숫자 합이 다르다면 합이 작은 문자열이 먼저 오도록
        return sumNum(s1) < sumNum(s2); //숫자 합에 대해 오름차순으로 정렬
    }
    return s1 < s2; //사전순
}

int main() {
    int n;          //입력할 시리얼번호 갯수
    vector<string> serial_num;  //시리얼 넘버를 담을 벡터

    //입력
    cin >> n;
    serial_num.assign(n, "");       //시리얼 넘버 벡터를 초기화
    for (int i = 0; i < n; i++) {
        cin >> serial_num[i];   //시리얼 넘버 입력받기
    }

    //연산
    sort(serial_num.begin(), serial_num.end(), cmp);    

    //출력
    for (int i = 0; i < n; i++) {
        cout << serial_num[i] << '\n';
    }
    return 0;
}