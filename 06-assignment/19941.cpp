#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string str;
    cin >> str;

    int cnt = 0;
    vector<bool> table(str.length(), false); // 햄버거가 먹혔는지 여부를 나타내는 배열

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'P') { // 사람이 있을 경우
            // 자신이 먹을 수 있는 범위 내에서 햄버거 찾기
            for (int j = max(i - k, 0); j <= min(i + k, (int)str.length() - 1); j++) {
                if (str[j] == 'H' && !table[j]) { // 햄버거가 있고, 그 햄버거가 먹히지 않았다면
                    table[j] = true; // 햄버거를 먹었다고 표시
                    cnt++; // 사람 수 증가
                    break; //한 사람은 한 개의 햄버거만 먹을 수 있음
                }
            }
        }
    }

    cout << cnt << '\n'; // 결과 출력
    return 0;
}
