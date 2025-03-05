#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX_N = 1000000;
vector<bool> is_prime(MAX_N + 1, true);
vector<int> primes;

// 에라토스테네스의 체를 이용한 소수 판별 및 저장
void Find() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= MAX_N; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= MAX_N; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Find(); // 소수 리스트 미리 생성

    int N;
    while (cin >> N, N != 0) {
        bool found = false;
        for (int prime : primes) {
            if (prime > N) break;
            if (is_prime[N - prime]) { // N - prime도 소수인지 확인
                cout << N << " = " << prime << " + " << (N - prime) << "\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }
    return 0;
}