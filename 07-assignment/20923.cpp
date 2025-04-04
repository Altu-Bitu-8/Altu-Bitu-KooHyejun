#include <iostream>
#include <deque>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    deque<int> do_deck, su_deck;
    deque<int> do_ground, su_ground;

    // 도도와 수연의 카드 입력 (맨 아래 → 맨 위)
    for (int i = 0; i < n; ++i) {
        int d, s;
        cin >> d >> s;
        do_deck.push_front(d); // 도도는 앞에서부터 넣음 (맨 위가 뒤쪽)
        su_deck.push_front(s); // 수연도 동일
    }

    // 게임 M번 진행
    for (int i = 0; i < m; ++i) {
        // 1. 턴 정하기
        bool is_do_turn = (i % 2 == 0);

        if (is_do_turn) {
            // 도도 턴
            if (do_deck.empty()) {
                cout << "su\n"; // 도도 카드 없음
                return 0;
            }
            int card = do_deck.back(); do_deck.pop_back();
            do_ground.push_front(card); // 맨 위에 놓기
        } else {
            // 수연 턴
            if (su_deck.empty()) {
                cout << "do\n"; // 수연 카드 없음
                return 0;
            }
            int card = su_deck.back(); su_deck.pop_back();
            su_ground.push_front(card); // 맨 위에 놓기
        }

        // 2. 종 치는 조건 체크
        bool do_bell = false, su_bell = false;

        if (!do_ground.empty() && do_ground.front() == 5) do_bell = true;
        if (!su_ground.empty() && su_ground.front() == 5) do_bell = true;

        if (!do_ground.empty() && !su_ground.empty() &&
            (do_ground.front() + su_ground.front() == 5)) {
            su_bell = true;
        }

        // 3. 종 친 사람이 카드 수거
        if (do_bell && su_bell) {
            // 동시에 만족할 수 없으므로, 도도가 우선
            su_bell = false;
        }

        if (do_bell) {
            // 도도가 먼저 종침 → 카드 수거
            while (!su_ground.empty()) {
                do_deck.push_front(su_ground.back());
                su_ground.pop_back();
            }
            while (!do_ground.empty()) {
                do_deck.push_front(do_ground.back());
                do_ground.pop_back();
            }
        } else if (su_bell) {
            // 수연이 종침
            while (!do_ground.empty()) {
                su_deck.push_front(do_ground.back());
                do_ground.pop_back();
            }
            while (!su_ground.empty()) {
                su_deck.push_front(su_ground.back());
                su_ground.pop_back();
            }
        }
    }

    // M번 턴 종료 후 결과 판단
    if (do_deck.size() > su_deck.size()) cout << "do\n";
    else if (do_deck.size() < su_deck.size()) cout << "su\n";
    else cout << "dosu\n"; // 비김

    return 0;
}
