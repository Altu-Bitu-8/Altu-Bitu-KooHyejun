#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    deque<char> dq(N, '?'); // 바퀴를 '?'로 초기화
    int S;
    char word;
    bool isValid = true;

    // 첫번째 입력
    cin >> S >> word;
    dq.back() = word;
    K--;

    while (K--) {
        cin >> S >> word;

        // S칸만큼 반시계방향 회전 (deque에서 back을 pop하고 front에 push)
        for (int i = 0; i < S; i++) {
            dq.push_front(dq.back());
            dq.pop_back();
        }

        // 기존 문자가 있고, 다른 문자로 바꾸려하면 모순!
        if (dq.back() != '?' && dq.back() != word) {
            cout << "!" << endl;
            return 0;
        }

        // 이미 사용된 문자인지 확인하기
        if (find(dq.begin(), dq.end() - 1, word) != dq.end() - 1) {
            isValid = false;
        }
        dq.back() = word;
    }

    // 최종 상태에서 한 번 더 회전 -> 원래 상태로 맞추기
    dq.push_front(dq.back());
    dq.pop_back();

    if (!isValid) {
        cout << "!" << endl;
        return 0;
    }

    // 결과 출력
    for (char c : dq) cout << c;
    cout << endl;

    return 0;
}

