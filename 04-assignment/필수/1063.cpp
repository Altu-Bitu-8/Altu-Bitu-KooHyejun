#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// 체스판에서의 이동방향 정의 
unordered_map<string, pair<int, int>> moving = {
    {"R", {0, 1}}, {"L", {0, -1}}, {"B", {-1, 0}}, {"T", {1, 0}},
    {"RT", {1, 1}}, {"LT", {1, -1}}, {"RB", {-1, 1}}, {"LB", {-1, -1}}
};

// 체스 위치 변환 함수 : A1 -> (0,0) 형식으로 변환
pair<int, int> stringToNumber(string pos) {
    return { pos[1] - '1', pos[0] - 'A' };
}

// 체스 위치 변환 함수: (0,0) -> A1 형식으로 변환
string numberToString(pair<int, int> pos) {
    return string(1, 'A' + pos.second) + to_string(pos.first + 1);
}

// 주어진 좌표가 체스판(8x8) 내에 있는지 확인하는 함수
bool isInside(pair<int, int> pos) {
    return (pos.first >= 0 && pos.first < 8 && pos.second >= 0 && pos.second < 8);
}

int main() {
    string kingSet, stoneSet;
    int N;
    cin >> kingSet >> stoneSet >> N;

    // string -> 좌표 변환
    pair<int, int> king = stringToNumber(kingSet);
    pair<int, int> stone = stringToNumber(stoneSet);

    for (int i = 0; i < N; i++) {
        string movee;
        cin >> movee;

        // 킹의 새로운 위치 계산
        pair<int, int> newKing = { king.first + moving[movee].first, king.second + moving[movee].second };

        // 킹이 체스판 내부에 있는지 확인
        if (!isInside(newKing)) continue;

        // 킹이 돌과 같은 위치로 이동하려는 경우
        if (newKing == stone) {
            pair<int, int> newStone = { stone.first + moving[movee].first, stone.second + moving[movee].second };

            // 돌이 체스판 내부에 있는지 확인
            if (!isInside(newStone)) continue;

            stone = newStone; // 돌 이동
        }
        king = newKing; // 킹 이동
    }

    // 최종 위치 출력
    cout << numberToString(king) << "\n";
    cout << numberToString(stone) << "\n";

    return 0;
}
