#include <iostream>

using namespace std;

int main() {
    int E, S, M;
    cin >> E >> S >> M;

    int year = 1; // 첫 해는 항상 1부터 시작

    while (true) {
        if ((year % 15 == (E % 15)) && (year % 28 == (S % 28)) && (year % 19 == (M % 19))) {
            cout << year << '\n';
            break;
        }
        year++;

    }
    return 0;
}