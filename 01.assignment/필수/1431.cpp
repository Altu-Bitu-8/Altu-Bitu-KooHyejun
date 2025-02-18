#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int summi(const string& s) {
    int sum = 0;
    for (char c : s) {
        if ('0' <= c && c <= '9') {
            sum += c - '0';
        }
    }
    return sum;
}
bool compare(const string& a, const string& b) {
    if (a.size() != b.size()) return a.size() < b.size();

    int sum1 = summi(a);
    int sum2 = summi(b);
    if (sum1 != sum2) return sum1 < sum2;

    return a < b;
}
int main() {
    int N;
    cin >> N;
    vector<string> serial(N);

    for (int i = 0; i < N; i++) {
        cin >> serial[i];
    }

    sort(serial.begin(), serial.end(), compare);

    for (const string& s : serial) {
        cout << s << '\n';
    }
}
