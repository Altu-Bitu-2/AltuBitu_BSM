#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

long long calTip(int n, vector<int>& tips) {    //팁을 계산하는 함수
    long long ans = 0;                    //리턴 할 팁
    for (int i = 0; i < n; i++) {       //전체 고객에 대해서 팁 계산
        int cur_tip = tips[i] - i;      //원래 주려했던 돈 -(받은 등수 - 1)
        if (cur_tip < 0) //음수면 팁에 더하지 않는데 처음에 내림차순 정렬했으므로 아예 break
            break;      
        ans += cur_tip;     //이전 팁에 현재 계산한 팁을 더한다
    }
    return ans;     // 전체 팁 값을 리턴
}

/**
 * 강호가 받을 수 있는 팁이 최댓값이 되려면 팁이 많은 사람의 순위가 높아야함
 * !주의! 주어지는 N의 최대 크기가 100,000이고 팁의 최대 크기가 100,000이므로
 *       정답의 최댓값은 10^5 * (10^5+1) / 2로 int 범위를 넘기 때문에 long long 을 써야 함
 */

int main() {        //메인함수
    int n;          //고객의 수

    //입력
    cin >> n;       //고객 수 입력받기
    vector<int> tips(n, 0);        //팁 벡터 n요소,  0으로 초기화
    for (int i = 0; i < n; i++) {   //전체 고객에 대해
        cin >> tips[i];             //팁 입력받기
    }
    //연산
    sort(tips.begin(), tips.end(), greater<>()); //내림차순 정렬
    //출력
    cout << calTip(n, tips) << '\n';        //팁 출력
    return 0;
}