#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    deque<char> dq(N, '?'); // ������ '?'�� �ʱ�ȭ
    int S;
    char word;
    bool isValid = true;

    // ù��° �Է�
    cin >> S >> word;
    dq.back() = word;
    K--;

    while (K--) {
        cin >> S >> word;

        // Sĭ��ŭ �ݽð���� ȸ�� (deque���� back�� pop�ϰ� front�� push)
        for (int i = 0; i < S; i++) {
            dq.push_front(dq.back());
            dq.pop_back();
        }

        // ���� ���ڰ� �ְ�, �ٸ� ���ڷ� �ٲٷ��ϸ� ���!
        if (dq.back() != '?' && dq.back() != word) {
            cout << "!" << endl;
            return 0;
        }

        // �̹� ���� �������� Ȯ���ϱ�
        if (find(dq.begin(), dq.end() - 1, word) != dq.end() - 1) {
            isValid = false;
        }
        dq.back() = word;
    }

    // ���� ���¿��� �� �� �� ȸ�� -> ���� ���·� ���߱�
    dq.push_front(dq.back());
    dq.pop_back();

    if (!isValid) {
        cout << "!" << endl;
        return 0;
    }

    // ��� ���
    for (char c : dq) cout << c;
    cout << endl;

    return 0;
}

