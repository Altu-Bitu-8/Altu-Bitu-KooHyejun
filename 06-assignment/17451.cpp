#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;  // 행성의 개수 n입력

    // speed 벡터에 각 구간에서 필요한 최소 속도 입력
    vector<int> speed(n);
    for (int i = 0; i < n; ++i) {
        cin >> speed[i];  // 각 구간의 최소 속도 값 입력
    }

    // speed 배열을 역순으로 처리해야 하므로 뒤집음
    reverse(speed.begin(), speed.end());

    long long result = 0;  // 지구에서 올려야 하는 최소 속도 (초기값은 0)

    // 각 구간을 처리하면서 최소 속도를 계산
    for (int i = 0; i < n; ++i) {
        // 현재 speed[i]가 result보다 크면 result를 speed[i]로 설정
        if (result <= speed[i]) {
            result = speed[i];  // 현재 속도가 충분하지 않으면 speed[i]만큼 올려야 한다.
        }

        // 현재 result가 speed[i]의 배수가 아니면, 최소 배수로 맞춰야 한다.
        // result % speed[i] != 0 : result가 speed[i]의 배수가 아닌 경우
        if (result % speed[i]) {
            // result를 speed[i]의 배수로 맞추기 위해서, 최소 배수로 올림
            result = (result / speed[i] + 1) * speed[i];
        }
    }

    // 최종적으로 계산된 최소 속도를 출력
    cout << result << '\n';

    return 0;
}
