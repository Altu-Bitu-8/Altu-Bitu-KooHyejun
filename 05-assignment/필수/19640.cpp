#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <cstdio>
using namespace std;

int N, M, K;
int employee[2][100001] = { 0 }; // 근무일수와 급한 정도를 저장

// 우선순위 큐를 위한 비교 연산자
struct PriorityCompare {
    bool operator()(tuple<int, int, int> a, tuple<int, int, int> b) {
        if (get<1>(a) == get<1>(b)) { // 근무일수가 같다면
            if (get<2>(a) == get<2>(b)) { // 화장실 급한 정도도 같다면
                return ((get<0>(a) - 1) % M) > ((get<0>(b) - 1) % M); // 줄 번호 비교
            }
            return get<2>(a) < get<2>(b); // 화장실 급한 정도로 우선순위 결정
        }
        return get<1>(a) < get<1>(b); // 근무일수로 우선순위 결정
    }
};

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, PriorityCompare> bathroomQueue;

int main() {
    scanf("%d %d %d", &N, &M, &K);

    // 직원 데이터 입력
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &employee[0][i], &employee[1][i]);
    }

    // 초기 줄의 첫 번째 사람들 삽입
    for (int i = 1; i <= M; i++) {
        bathroomQueue.push(make_tuple(i, employee[0][i], employee[1][i]));
    }

    int currentIdx, usedCount = 0;

    // 데카가 화장실을 사용할 때까지 처리
    while (get<0>(bathroomQueue.top()) != K + 1) { // 데카가 줄에 올 차례가 되면 종료
        currentIdx = get<0>(bathroomQueue.top()); // 현재 선두의 줄 번호
        bathroomQueue.pop(); // 현재 선두 제거

        // 해당 줄의 다음 사람을 큐에 추가
        if (currentIdx + M <= N) { // 배열 범위를 벗어나지 않는지 확인
            bathroomQueue.push(make_tuple(currentIdx + M, employee[0][currentIdx + M], employee[1][currentIdx + M]));
        }

        usedCount++; // 화장실을 사용한 사람 수 증가
    }

    // 결과 출력
    printf("%d\n", usedCount);

    return 0;
}
