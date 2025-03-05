#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// �� ���� �ִ������� ���ϴ� �Լ�
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int N, S;
    cin >> N >> S; // ������ �� N, �������� ��ġ S

    vector<int> sisters(N);
    for (int i = 0; i < N; i++) {
        cin >> sisters[i]; // �� ������ ��ġ
    }

    // ù��° ������ �������� ��ġ���̺��� GCD ������
    int result = abs(sisters[0] - S);

    // ������ ��������� ���̸� ����Ͽ� GCD�� ���ϱ�
    for (int i = 1; i < N; i++) {
        result = gcd(result, abs(sisters[i] - S));
    }

    // ������ D���� �ִ� ���
    cout << result << endl;

    return 0;
}
