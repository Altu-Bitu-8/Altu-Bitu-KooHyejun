#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 두 수의 최대공약수를 구하는 함수
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int N, S;
    cin >> N >> S; // 동생의 수 N, 수빈이의 위치 S

    vector<int> sisters(N);
    for (int i = 0; i < N; i++) {
        cin >> sisters[i]; // 각 동생의 위치
    }

    // 첫번째 동생과 수빈이의 위치차이부터 GCD 계산시작
    int result = abs(sisters[0] - S);

    // 나머지 동생들과의 차이를 계산하여 GCD를 구하기
    for (int i = 1; i < N; i++) {
        result = gcd(result, abs(sisters[i] - S));
    }

    // 가능한 D값의 최댓값 출력
    cout << result << endl;

    return 0;
}
