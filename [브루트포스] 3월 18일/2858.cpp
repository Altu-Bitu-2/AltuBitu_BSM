#include <iostream>

using namespace std;

//기숙사 바닥의 l(높이), w(넓이) 구해서 리턴하는 함수
pair<int, int> length(int r, int b) {   //r: 빨간 타일 갯수, b: 갈색 타일 갯수
    int area = r + b;   //방의 넓이는 전체 타일의 합
    for (int i = area; i > 0; i--) { //i = l(높이) 의 값
        if (area % i != 0) { //w 가 정수가 아니라면 넘어감
            continue;
        }
        int w = area / i;   //w 세로길이는 가로 길이를 전체 넓이로 나눴을 때 나오는 정수값
        if (r == ((i + w) * 2 - 4)) { //빼지는 4는 모서리 중복 갯수
            return make_pair(i, w);     //높이 넓이 쌍을 리턴, 미지수 두 개에 대한 2개의 조건으로 나온 값이므로 가능한 쌍 1개
        }
    }
}

/**
 * [기숙사 바닥 문제]
 * 빨간 타일: 테두리를 채움, 갈색 타일: 나머지
 * 문제 입력에 만족하는 방의 크기 l, w (l > w)를 출력하는 문제
 *
 * [풀이]
 * 기숙사 바닥의 넓이는 타일의 개수의 총합인 r + b
 * l(높이)이 r + b인 사각형부터 검사 (w = (r + b) / l) -> 테두리 타일 개수가 r개와 같다면 정답
 * 테두리 개수 = (l + w) * 2 - 4(겹치는 부분)
 * 입력 범위는 최대 r + b = 2,005,000 이므로 접근 가능!
 */

int main() {
    int r, b; //r: 빨간 타일 개수, b: 갈색 타일 개수

    //입력
    cin >> r >> b;

    //연산
    pair<int, int> result = length(r, b);

    //출력
    cout << result.first << ' ' << result.second << '\n'; //l 과 w 출력
    return 0;
}