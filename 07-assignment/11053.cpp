#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);      // 입력수열 저장하기기
    vector<int> dp(n, 1);  //dp[i] = A[i]를 마지막으로 하는 LIS의 길이 (초기값은 1)

    // 수열 입력 받기
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // LIS 계산
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            // 이전 항보다 현재 항이 크면 증가 수열 가능
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1); // 더 긴 수열이 가능하다면 갱신
            }
        }
    }

    // dp 배열에서 가장 큰 값이 최장 증가 부분 수열의 길이
    int result = *max_element(dp.begin(), dp.end());
    cout << result << '\n';

    return 0;
}
