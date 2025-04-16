#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, n, bitmask = 0;
    cin >> M;
    string cmd;

    while (M--) {
        cin >> cmd;

        if (cmd == "add") {
            cin >> n;
            bitmask |= (1 << n);
        }
        else if (cmd == "remove") {
            cin >> n;
            bitmask &= ~(1 << n);
        }
        else if (cmd == "check") {
            cin >> n;
            cout << ((bitmask & (1 << n)) ? 1 : 0) << '\n';
        }
        else if (cmd == "toggle") {
            cin >> n;
            bitmask ^= (1 << n);
        }
        else if (cmd == "all") {
            bitmask = (1 << 21) - 1;  // 1~20까지 모두 포함
        }
        else if (cmd == "empty") {
            bitmask = 0;
        }
    }

    return 0;
}
