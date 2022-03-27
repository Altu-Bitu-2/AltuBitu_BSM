#include <iostream>
#include <vector>
#include <algorithm>    //prev_permutation 이용

using namespace std;

//prev_permutation()을 활용한 조합을 이용한 풀이
int blackJackC(int n, int m, vector<int>& card) {   //n:카드의 갯수, m: 가까워져야하는 값,  card: 카드벡터
    int ans = 0; //정답

    vector<bool> is_selected(n, false); //고른 카드가 true   선택 여부에 관한  vector
    for (int i = 0; i < 3; i++) { //3장 카드 고른 것으로 초기화
        is_selected[i] = true;  
    }

    do {
        int sum = 0; //고른 3장의 카드 합 저장
        for (int i = 0; i < n; i++) {
            if (is_selected[i]) {   //true로 선택된 3장의 카드 합 계산
                sum += card[i];     //3장의 카드 합을 sum 에 저장
            }
        }
        //m과 가장 가까운 카드 구하기
        if (sum <= m) { 
            ans = max(ans, sum);    //이전 ans와 비교하여 값이 큰 것을 ans로 변경
        }
    } while (prev_permutation(is_selected.begin(), is_selected.end())); //3개의 true가 있는 전체 경우를 반복
    return ans;  //값 리턴
}

//3중 for문 풀이
int blackJackFor(int n, int m, vector<int>& card) {
    int ans = 0; //정답

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {   //전체 카드에서 3개 선택하는 전체 경우를 3중 for문으로 구현
                int sum = card[i] + card[j] + card[k];
                if (sum > m) { //m을 넘었다면
                    break; //(생각해보세요) 바로 return ans; 를 하면 어떻게 될까요?
                            // m에 더 가까워질 수 있는 경우가 고려되지 않을 수 있음
                }
                ans = max(ans, sum);    //이전 값과 현재 구한 합 중 더 큰 것 선택
            }
        }
    }
    return ans;
}

/**
 * [ 블랙잭 ] - 단순 구현
 * 카드가 최대 100장이므로,
 * C(100, 3) < 100*100*100 = 1,000,000 -> 브루트포스 충분히 가능
 *
 * ver1. 3중 for문 이용해서 구현
 * +) 코드의 효율성을 높이기 위해, 카드를 사전에 정렬하여 M을 넘어가는 순간 반복 종료 (이때, 한 반복만 빠져나오는 것 주의!)
 *
 * ver2. prev_permutation()을 활용하여 모든 조합을 구해서 구현
 */

int main() {
    int n, m;   //n: 카드의 갯수, m: 세 카드의 합의 기준이 될 값

    //입력
    cin >> n >> m;  
    vector<int> card(n, 0); //바닥에 놓일 카드에 관한 vector, 0으로 초기화
    for (int i = 0; i < n; i++) {   
        cin >> card[i];     // card벡터에 입력
    }   

    //연산
    //조합 풀이
    int ans = blackJackC(n, m, card);   

    //3중 for 문 풀이
    //sort(card.begin(), card.end());
    //int ans = blackJackFor(n, m, card);

    //출력
    cout << ans;
    return 0;
}