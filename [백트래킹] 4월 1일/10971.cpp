#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e8;

vector<bool> visited; //방문 검사 배열
vector<vector<int>> matrix; //비용 행렬
int n, ans = INF; //최소 비용 저장 위해 미리 최댓값으로 초기화

/**
 * !생각해보기! 함수의 각 인자는 각각 어떤 역할을 하고 있나요?
 * cnt: 방문한 도시의 수
 * cur_city: 현재 방문 도시
 * cost: 
 */
void backtracking(int cnt, int cur_city, int cost) {
    if (cost >= ans) { //생각해보기 : 이 조건문이 없으면 어떻게 될까요?
        return;
    }
    if (cnt == n) { //종료 조건 : n개의 도시를 순회했음
        //출발 도시(0)로 다시 돌아올 수 있는지 확인
        if (matrix[cur_city][0] != 0) { //0이 아닐 경우 이동 가능
            ans = min(ans, cost + matrix[cur_city][0]);     //이전 최소비용과 현재 비용에서 0번도시로 돌아가는 비용
            //합한 것 둘 중 최소 비용 선택
        }
        return;
    }
    for (int i = 0; i < n; i++) { //cur_city에서 도시 i로 이동
        if (matrix[cur_city][i] && !visited[i]) { //길이 있고, 아직 방문하지 않은 도시
            visited[i] = true;  //방문 표시
            backtracking(cnt + 1, i, cost + matrix[cur_city][i]);
            visited[i] = false; //방문상태 원상복귀
        }
    }
}

/**
 * 백트래킹 풀이 (4ms)
 *
 * 한 사이클을 만들면, 어느 도시에서 시작하든 값은 같으므로 0번 도시부터 시작하는 경우만 검사하면 된다.
 */

int main() {
    //입력
    cin >> n;
    visited.assign(n, false);   //n개 도시 미방문으로 초기화
    matrix.assign(n, vector<int>(n, 0)); //n by n matrix 0으로 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];    //matrix 배용 행렬 입력
        }
    }

    //연산
    visited[0] = true; //0번도시 방문
    backtracking(1, 0, 0);      //0번도시 방문, 방문한 도시 1, 현재 비용 0

    //출력
    cout << ans;
    return 0;
}